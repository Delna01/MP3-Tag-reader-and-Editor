
# 🎵 MP3 Tag Reader and Editor (C Project)

## 📌 Description
The MP3 Tag Editor is a C-based application that allows users to view and edit metadata (ID3 tags) of MP3 files.  
It provides functionalities to display and modify fields such as title, artist, album, year, and more.

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

## ⚙️ Build
Compile all source files with gcc:

```bash
gcc main.c view.c edit.c -o mp3tag
```

---

## 🚀 Usage

### View all tags in an MP3 file
```bash
./mp3tag -v <file.mp3>
```

### Edit a specific tag
```bash
./mp3tag -e <file.mp3> -t/-a/-A/-y/-g/-c <new_value>
```

### Show help
```bash
./mp3tag -h
```

---

## 📖 How It Works

### Viewing Tags (view.c)
- Opens the MP3 file in binary mode  
- Skips the 10-byte ID3v2 header  
- Reads ID3v2 frames (tag ID + size)  
- Displays tag contents (TIT2, TPE1, TALB, TYER, TCON, COMM)  

### Editing Tags (edit.c)
- Opens original MP3 and creates a temporary file  
- Copies header and frames  
- Updates only the selected tag  
- Writes back updated file  

---

## ⚠️ Limitations
- Edits only existing tags  
- Does not support ID3v1  
- No GUI (CLI only)  

---

## 📂 Project Structure
```
Delna MP3 Tag/
│
├── main.c   # Entry point — argument parsing and CLI routing
├── view.c   # Tag viewer — reads and displays ID3v2 frames
├── edit.c   # Tag editor — rewrites MP3 with updated tag values
├── mp3.h    # Header file — function declarations
└── a.out    # Compiled binary (Linux)
```

---

## 👩‍💻 Author
Delna Joseph

