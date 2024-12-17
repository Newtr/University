import tkinter as tk
from tkinter import filedialog, messagebox, ttk
import time
import os
import psutil
from chacha20_cipher import ChaCha20Cipher
from twofish_cipher import TwofishCipher

RESULTS_FILE = "Results.txt"

# Функция для определения алгоритма по заголовку файла
def detect_algorithm(file_path):
    with open(file_path, 'rb') as f:
        header = f.read(8)  # Считываем первые 8 байт
    if header == b'ChaCha20':
        return 'ChaCha20'
    elif header == b'TwoFish':
        return 'TwoFish'
    else:
        return 'Unknown'

# Класс для анализа алгоритмов
class CipherAnalysisApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Comparative Analysis: ChaCha20 vs Twofish")
        self.root.geometry("800x600")
        self.setup_ui()
        
        # Переменные для анализа
        self.key = os.urandom(32)  # 256-битный ключ для обоих алгоритмов
        self.nonce = os.urandom(16)  # Nonce для ChaCha20
        self.plaintext = b""  # Исходные данные
        self.test_number = self.get_last_test_number()  # Номер последнего теста
        self.results = ""

    def setup_ui(self):
        """Создание графического интерфейса приложения."""
        # Заголовок
        title_label = tk.Label(self.root, text="Cipher Analysis Tool", font=("Arial", 18, "bold"))
        title_label.pack(pady=10)
        
        # Загрузка файла
        upload_btn = tk.Button(self.root, text="Upload File", command=self.upload_file)
        upload_btn.pack(pady=5)
        self.file_label = tk.Label(self.root, text="No file uploaded", fg="grey")
        self.file_label.pack()

        # Кнопки запуска анализа и сохранения результатов
        analyze_btn = tk.Button(self.root, text="Run Analysis", command=self.run_analysis)
        analyze_btn.pack(pady=5)
        
        save_btn = tk.Button(self.root, text="Save Results", command=self.save_results)
        save_btn.pack(pady=5)

        # Прогресс-бар
        self.progress = ttk.Progressbar(self.root, orient=tk.HORIZONTAL, length=400, mode="determinate")
        self.progress.pack(pady=20)

        # Текстовое поле для вывода результатов
        self.result_text = tk.Text(self.root, height=15, width=90, wrap=tk.WORD)
        self.result_text.pack(pady=10)

    def upload_file(self):
        """Загрузка файла для шифрования."""
        file_path = filedialog.askopenfilename(filetypes=[("Text Files", "*.txt")])
        if file_path:
            with open(file_path, "rb") as f:
                self.plaintext = f.read()
            algorithm = detect_algorithm(file_path)
            self.file_label.config(text=f"File uploaded: {os.path.basename(file_path)}")
        else:
            messagebox.showwarning("Warning", "No file selected!")

    def multiple_encryption_test(self, cipher, iterations=100):
        """Тест производительности при многократном шифровании."""
        start_time = time.perf_counter()
        data = self.plaintext
        for _ in range(iterations):
            data = cipher.encrypt(data)
        total_time = time.perf_counter() - start_time
        return total_time
    
    def test_with_large_data(self, cipher, size_mb=10):
        """Тест шифрования на больших данных."""
        large_data = b"A" * (size_mb * 1024 * 1024)
        start_time = time.perf_counter()
        cipher.encrypt(large_data)
        return time.perf_counter() - start_time

    def run_analysis(self):
        """Запуск анализа: шифрование и дешифрование обоими методами."""
        if not self.plaintext:
            messagebox.showerror("Error", "Please upload a file first!")
            return
        
        self.result_text.delete("1.0", tk.END)
        self.progress["value"] = 0
        self.root.update_idletasks()
        self.results = ""

        # Шаг 1: Анализ ChaCha20
        self.results += f"Test {self.test_number}\n"
        self.results += "Running ChaCha20 Analysis...\n"
        chacha_cipher = ChaCha20Cipher(self.key, self.nonce)

        start_time = time.perf_counter()
        encrypted_chacha = chacha_cipher.encrypt(self.plaintext)
        encrypt_time = time.perf_counter() - start_time

        start_time = time.perf_counter()
        decrypted_chacha = chacha_cipher.decrypt(encrypted_chacha)
        decrypt_time = time.perf_counter() - start_time

        chacha_size = len(encrypted_chacha)
        self.results += f"ChaCha20 Encrypt Time: {encrypt_time:.8f} seconds\n"
        self.results += f"ChaCha20 Decrypt Time: {decrypt_time:.8f} seconds\n"

        # Шаг 2: Анализ Twofish
        self.results += "Running Twofish Analysis...\n"
        twofish_cipher = TwofishCipher(self.key)

        start_time = time.perf_counter()
        encrypted_twofish = twofish_cipher.encrypt(self.plaintext)
        encrypt_time = time.perf_counter() - start_time

        start_time = time.perf_counter()
        decrypted_twofish = twofish_cipher.decrypt(encrypted_twofish)
        decrypt_time = time.perf_counter() - start_time

        twofish_size = len(encrypted_twofish)
        self.results += f"Twofish Encrypt Time: {encrypt_time:.8f} seconds\n"
        self.results += f"Twofish Decrypt Time: {decrypt_time:.8f} seconds\n"

        # Проверка дешифрования
        if decrypted_chacha == self.plaintext and decrypted_twofish == self.plaintext:
            self.results += "Decryption Test: PASSED\n"
        else:
            self.results += "Decryption Test: FAILED\n"

        # Вывод результатов
        self.result_text.insert(tk.END, self.results)
        self.progress["value"] = 100
        self.root.update_idletasks()

    def save_results(self):
        """Сохранение результатов анализа в файл."""
        with open(RESULTS_FILE, "a") as file:
            file.write(self.results)
        self.test_number += 1
        messagebox.showinfo("Success", f"Results saved to {RESULTS_FILE}")

    def get_last_test_number(self):
        """Определяет номер последнего теста из файла результатов."""
        if not os.path.exists(RESULTS_FILE):
            return 1
        with open(RESULTS_FILE, "r") as file:
            content = file.read()
        tests = content.count("Test ")
        return tests + 1

# Запуск приложения
if __name__ == "__main__":
    root = tk.Tk()
    app = CipherAnalysisApp(root)
    root.mainloop()
