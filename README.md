# my_ls

A low-level C implementation of the Linux ls utility designed to interface directly with the file system to retrieve and format directory metadata.

---

## 🧠 Description

This project replicates the core functionality of the ls binary by utilizing POSIX system calls to read directory streams and extract file attributes. Developed in C, it focuses on memory efficiency and precise data parsing from the underlying filesystem structures.

Implemented flags:

* -a (All): Displays hidden files by including entries starting with a dot (.).
* -d (Directory): Lists directories themselves rather than their contents.
* -l (Long listing): Displays detailed metadata including permissions, owner, size, and modification timestamp.
* -t (Time): Sorts the output based on the last modification time instead of alphabetical order.
* -r (Reverse): Reverses the sorting order of the output.

---

## 🚀 Getting started

### Installing

**Clone the repository:**

```bash
git clone https://github.com/QUINTIN-Killian/my_ls.git
cd my_ls
```

### Executing program

**Compiling:**

```bash
make
```

**Executing:**

```bash
./my_ls [-a] [-l] [-r] [-d] [-t]
```

Example:

```bash
./my_ls -l /usr/
```

---

## 👥 Authors

* [@Killian QUINTIN](https://github.com/QUINTIN-Killian)
