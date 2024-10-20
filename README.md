# Ringkas Dokumen
Buat yang malas baca, gunain aja ini buat ambil substansi dari e-book &amp; pdf lainnya.

## Penting!
Pastikan Ollama sudah terinstall

## Installation

1. Clone repository:
    ```powershell
    git clone https://github.com/your-username/repository-name.git
    cd ringkasDokumen
    ```

2. Install dependencies:
    ```powershell
    pip install -r requirements.txt
    ```

3. Pastikan Anda telah menginstal Ollama dan mengunduh model llama3.2.:
    ```powershell
    ollama pull llama3.2
    ```

## Penggunaan

1. Jalankan script dengan lokasi path file.pdf (beri nama pada .pdf tanpa spasi):
    ```powershell
    python.exe script.py path/to/your/file.pdf
    ```

Teks akan diekstrak dari PDF dan dianalisis menggunakan model llama3.2. Teks yang diekstrak akan disimpan di direktori `Output` yang terletak di direktori yang sama dengan skrip
