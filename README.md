
# 🎵 MP3-Tag-reader-and-Editor(C Project)
This project is a command-line based MP3 Tag Reader and Editor written in C. It allows users to view and modify metadata (ID3 tags) in MP3 files such as Title, Artist, Album, Year, Genre, and Comments.

---

## 📁 Project Structure
Delna MP3 Tag/
├── main.c      # Entry point — argument parsing and CLI routing
├── view.c      # Tag viewer — reads and displays ID3v2 frames
├── edit.c      # Tag editor — rewrites MP3 with updated tag values
├── mp3.h       # Header file — function declarations
└── a.out       # Compiled binary (Linux)

---

## 🚀 Features
- View MP3 tag details
- Edit metadata fields:
  - Title
  - Artist
  - Album
  - Year
  - Genre
  - Comments
- Command-line based program
- Modular implementation using multiple C files

---

## 🛠️ Technologies Used
- Language: C
- Concepts:
  - File handling (fopen, fread, fwrite)
  - Structures
  - Command-line arguments
  - Binary file processing

---

## 🛠️ Build
Compile all source files with gcc:
bashgcc main.c view.c edit.c -o mp3tag

---

## 🚀 Usage
bash# View all tags in an MP3 file
./mp3tag -v <file.mp3>

# Edit a specific tag
./mp3tag -e <file.mp3> -t/-a/-A/-y/-g/-c <new_value>

# Show help
./mp3tag -h

---

## ⚙️ How It Works
Viewing Tags (view.c)

Opens the MP3 file in binary mode
Skips the 10-byte ID3v2 header
Iterates through ID3v2 frames, reading the 4-byte tag ID and 4-byte size field
Byte-swaps the size field (big-endian → little-endian) using the convert() helper
Prints the content of recognized frames (TIT2, TPE1, TALB, TYER, TCON, COMM)

Editing Tags (edit.c)

Opens the original MP3 as read-only and creates a temporary file (new.mp3)
Copies the 10-byte ID3v2 header as-is
Iterates through all frames; when the target frame is found, writes the new value in its place with a corrected size
All other frames are copied unchanged, preserving audio data integrity
Replaces the original file with the updated temporary file on success

---

## ⚠️ Limitations

Edits only existing tags — cannot add a tag that is not already present in the file
The edited output is written to a temporary file new.mp3 in the current working directory during processing
Does not support ID3v1 tags (last 128 bytes of MP3)
Does not handle unsynchronisation or extended ID3v2 headers

---

## 👤 Author
Delna Joseph



## 📂 Project Structure
