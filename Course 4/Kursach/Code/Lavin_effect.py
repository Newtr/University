import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms
from chacha20_cipher import ChaCha20Cipher
from twofish_cipher import TwofishCipher
from Crypto.Util.Padding import pad, unpad

def hamming_distance(b1, b2):
    """Вычисляет расстояние Хэмминга между двумя байтовыми строками."""
    return sum(bin(x ^ y).count('1') for x, y in zip(b1, b2))

def analyze_avalanche_effect(file_path):
    # Чтение исходного файла
    with open(file_path, 'rb') as file:
        original_data = file.read()

    if len(original_data) < 16:
        raise ValueError("The file content must be at least 16 bytes long for encryption.")

    # Ключи и нонсы
    key_chacha20 = os.urandom(32)  # Ключ длиной 256 бит для ChaCha20
    nonce_chacha20 = os.urandom(16)  # Нонс длиной 128 бит
    key_twofish = os.urandom(16)  # Ключ длиной 128 бит для Twofish

    # Шифрование ChaCha20
    chacha_cipher = ChaCha20Cipher(key_chacha20, nonce_chacha20)
    chacha20_encrypted = chacha_cipher.encrypt(original_data)

    # Модификация данных (инверсия первого бита)
    modified_data = bytearray(original_data)
    modified_data[0] ^= 1

    # Повторное шифрование ChaCha20
    chacha20_encrypted_modified = chacha_cipher.encrypt(modified_data)

    # Вычисление расстояния Хэмминга для ChaCha20
    chacha20_distance = hamming_distance(chacha20_encrypted, chacha20_encrypted_modified)

    # Шифрование Twofish
    twofish_cipher = TwofishCipher(key_twofish)
    padded_data = pad(original_data, twofish_cipher.block_size)
    twofish_encrypted = twofish_cipher.encrypt(padded_data)

    # Шифрование модифицированных данных Twofish
    padded_modified_data = pad(modified_data, twofish_cipher.block_size)
    twofish_encrypted_modified = twofish_cipher.encrypt(padded_modified_data)

    # Вычисление расстояния Хэмминга для Twofish
    twofish_distance = hamming_distance(twofish_encrypted, twofish_encrypted_modified)

    # Вывод результатов
    print(f"ChaCha20 Hamming Distance: {chacha20_distance} bits")
    print(f"Twofish Hamming Distance: {twofish_distance} bits")

# Пример использования
if __name__ == "__main__":
    file_path = input("Enter the path to the text file: ")
    try:
        analyze_avalanche_effect(file_path)
    except Exception as e:
        print(f"Error: {e}")
