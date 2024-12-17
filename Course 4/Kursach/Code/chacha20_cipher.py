from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
import os

class ChaCha20Cipher:
    def __init__(self, key: bytes, nonce: bytes):
        self.key = key  # Ключ длиной 32 байта
        self.nonce = nonce  # Нонс длиной 16 байт

    def encrypt(self, plaintext: bytes) -> bytes:
        cipher = Cipher(algorithms.ChaCha20(self.key, self.nonce), mode=None, backend=default_backend())
        encryptor = cipher.encryptor()
        return encryptor.update(plaintext)

    def decrypt(self, ciphertext: bytes) -> bytes:
        cipher = Cipher(algorithms.ChaCha20(self.key, self.nonce), mode=None, backend=default_backend())
        decryptor = cipher.decryptor()
        return decryptor.update(ciphertext)

    def save_to_file(self, filename: str, data: bytes):
        with open(filename, 'wb') as f:
            f.write(b'ChaCha20:' + data)

    def read_from_file(self, filename: str) -> bytes:
        """Чтение данных из файла с пропуском заголовка."""
        with open(filename, 'rb') as f:
            data = f.read()
        if data.startswith(b'ChaCha20:'):
            return data[len(b'ChaCha20:'):]  # Убираем заголовок
        else:
            raise ValueError("Invalid file format for ChaCha20")


# Пример использования
if __name__ == "__main__":
    key = os.urandom(32)  # Случайный ключ (32 байта)
    nonce = os.urandom(16)  # Случайный нонс (16 байт)

    # Чтение данных из файла MyInfoText.txt
    with open("MyInfoText.txt", "rb") as file:
        plaintext = file.read()

    chacha = ChaCha20Cipher(key, nonce)

    # Шифрование и сохранение в файл
    encrypted = chacha.encrypt(plaintext)
    chacha.save_to_file("ChaChaText.txt", encrypted)
    print("Encrypted text saved to ChaChaText.txt")

    # Чтение из файла и дешифрование
    encrypted_from_file = chacha.read_from_file("ChaChaText.txt")
    decrypted = chacha.decrypt(encrypted_from_file)
    print(f"Decrypted text: {decrypted.decode()}")
