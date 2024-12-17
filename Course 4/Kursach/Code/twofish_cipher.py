class TwofishCipher:
    def __init__(self, key: bytes):
        self.key = key
        self.block_size = 16  # Блоки по 16 байт

    def _pad(self, plaintext: bytes) -> bytes:
        padding_length = self.block_size - len(plaintext) % self.block_size
        return plaintext + bytes([padding_length] * padding_length)

    def _unpad(self, plaintext: bytes) -> bytes:
        padding_length = plaintext[-1]
        return plaintext[:-padding_length]

    def encrypt_block(self, block: bytes) -> bytes:
        key_sum = sum(self.key)
        return bytes((b + key_sum) % 256 for b in block)

    def decrypt_block(self, block: bytes) -> bytes:
        key_sum = sum(self.key)
        return bytes((b - key_sum) % 256 for b in block)

    def encrypt(self, plaintext: bytes) -> bytes:
        plaintext = self._pad(plaintext)
        ciphertext = b""
        for i in range(0, len(plaintext), self.block_size):
            block = plaintext[i:i + self.block_size]
            ciphertext += self.encrypt_block(block)
        return ciphertext

    def decrypt(self, ciphertext: bytes) -> bytes:
        plaintext = b""
        for i in range(0, len(ciphertext), self.block_size):
            block = ciphertext[i:i + self.block_size]
            plaintext += self.decrypt_block(block)
        return self._unpad(plaintext)

    def save_to_file(self, filename: str, data: bytes):
        with open(filename, 'wb') as f:
            f.write(b'TwoFish:' + data)

    def read_from_file(self, filename: str) -> bytes:
        """Чтение данных из файла с пропуском заголовка."""
        with open(filename, 'rb') as f:
            data = f.read()
        if data.startswith(b'TwoFish:'):
            return data[len(b'TwoFish:'):]  # Убираем заголовок
        else:
            raise ValueError("Invalid file format for TwoFish")


# Пример использования
if __name__ == "__main__":
    key = b"mysecretkey12345"  # 16-байтный ключ

    # Чтение данных из файла MyInfoText.txt
    with open("MyInfoText.txt", "rb") as file:
        plaintext = file.read()

    twofish = TwofishCipher(key)

    # Шифрование и сохранение в файл
    encrypted = twofish.encrypt(plaintext)
    twofish.save_to_file("TwofishText.txt", encrypted)
    print("Encrypted text saved to TwofishText.txt")

    # Чтение из файла и дешифрование
    encrypted_from_file = twofish.read_from_file("TwofishText.txt")
    decrypted = twofish.decrypt(encrypted_from_file)
    print(f"Decrypted text: {decrypted.decode()}")
