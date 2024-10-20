import os
import sys
import PyPDF2

def extract_text_from_pdf(pdf_path):
    with open(pdf_path, 'rb') as file:
        reader = PyPDF2.PdfReader(file)
        text = ''
        for page in reader.pages:
            text += page.extract_text()

    base_name = os.path.basename(pdf_path)
    file_name = os.path.splitext(base_name)[0] + ".txt"
    script_dir = os.path.dirname(os.path.abspath(__file__))
    output_dir = os.path.join(script_dir, "Output")
    output_path = os.path.join(output_dir, file_name)

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    with open(output_path, 'w', encoding='utf-8') as text_file:
        text_file.write(text)

    print(f"Extracted text saved to: {output_path}")
    return output_path

def analyze_text_with_ollama(txt_path):
    command = f'Get-Content -Path "{txt_path}" | ollama run llama3.2 --verbose "ringkas dengan detail dan sistematis"'
    os.system(f'powershell -Command "{command}"')
    print(f"Analyzing text: {txt_path}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python script.py <path_to_pdf>")
        sys.exit(1)

    pdf_path = sys.argv[1]
    txt_path = extract_text_from_pdf(pdf_path)
    analyze_text_with_ollama(txt_path)

if __name__ == "__main__":
    main()

