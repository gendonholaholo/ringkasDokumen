## Deskripsi
Proyek ini adalah sebuah alat yang dapat mengekstrak teks dari file PDF, menyimpannya dalam format TXT, dan menganalisis teks tersebut menggunakan model Ollama Llama3.2 untuk menghasilkan ringkasan dokumen. Program ini juga secara otomatis memeriksa dan menginstal dependensi yang diperlukan (Poppler dan Ollama) jika belum terpasang.

## Instalasi
### Prasyarat
- **Scoop**: Manajer paket untuk Windows.
- **g++**: Kompiler C++.
- **GPU RTX Series**: Agar berjalan optimal.

### Langkah-langkah
1. **Clone repositori ini**:
    ```powershell
    git clone https://github.com/gendonholaholo/ringkasDokumen.git
    cd ringkasinDokumen
    ```

2. **Kompilasi Program**:
    ```powershell
    g++ -o gos_ringkasin gos_ringkasin.cpp
    ```

## Penggunaan
1. **Jalankan Program**:
    ```powershell
    ./gos_ringkasin path/to/your/file.pdf
    ```
    Program akan melakukan hal berikut:
    - Memeriksa dan menginstal Poppler dan Ollama jika belum terpasang.
    - Menarik model Llama3.2 jika belum tersedia.
    - Mengekstrak teks dari PDF dan menyimpannya di direktori output.
    - Menganalisis teks yang diekstrak menggunakan Ollama.
