import tkinter as tk
from tkinter import filedialog, messagebox
from tkinter import ttk
import subprocess

def select_input_file():
    input_file_path.set(filedialog.askopenfilename())

def run_parser():
    input_path = input_file_path.get()
    output_path1 = "assembly.txt"
    output_path2 = "assembly.txt"
    output_path3 = "assembly.txt"
    
    if not input_path:
        messagebox.showerror("Error", "Input file path is required")
        return
    
    try:
        # Run the parser executable (a.exe) on the input file and capture output
        result = subprocess.run(["a.exe", input_path], capture_output=True, text=True)
        
        # Print the output to the terminal
        print(result.stdout)
        if result.stderr:
            print(result.stderr)
        
        # Assuming the function writes to output files, read the output files
        with open(output_path1, "r") as file1:
            output_text1.delete(1.0, tk.END)  # Clear existing content
            output_text1.insert(tk.END, file1.read())
        
        with open(output_path2, "r") as file2:
            output_text2.delete(1.0, tk.END)  # Clear existing content
            output_text2.insert(tk.END, file2.read())

        with open(output_path3, "r") as file3:
            output_text3.delete(1.0, tk.END)  # Clear existing content
            output_text3.insert(tk.END, file3.read())
        
        messagebox.showinfo("Success", "Parsing and function execution completed successfully")
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {str(e)}")

def toggle_fullscreen(event=None):
    root.state = not root.state  # Toggle state
    root.attributes("-fullscreen", root.state)
    return "break"

def end_fullscreen(event=None):
    root.state = False
    root.attributes("-fullscreen", False)
    return "break"

# Create the main window
root = tk.Tk()
root.title("Parser GUI")

# Set the background color to blue
root.configure(bg='black')

# Enable resizing
root.resizable(True, True)

# Set full screen toggle
root.bind("<F11>", toggle_fullscreen)
root.bind("<Escape>", end_fullscreen)
root.state = False

# Define StringVars to hold file paths
input_file_path = tk.StringVar()

# Create a Notebook
notebook = ttk.Notebook(root)
notebook.grid(row=4, columnspan=3, padx=10, pady=10, sticky="nsew")

# Create frames for each tab
frame1 = ttk.Frame(notebook)
frame2 = ttk.Frame(notebook)
frame3 = ttk.Frame(notebook)
notebook.add(frame1, text='QUADRAPLES')
notebook.add(frame2, text='SYNTAX ERRORS')
notebook.add(frame3, text='SEMANTIC ERRORS')

# Create Text widgets in each frame
output_text1 = tk.Text(frame1, wrap=tk.WORD, width=80, height=20)
output_text1.pack(expand=True, fill=tk.BOTH)

output_text2 = tk.Text(frame2, wrap=tk.WORD, width=80, height=20)
output_text2.pack(expand=True, fill=tk.BOTH)

output_text3 = tk.Text(frame3, wrap=tk.WORD, width=80, height=20)
output_text3.pack(expand=True, fill=tk.BOTH)

# Create and place widgets with styles
style = ttk.Style()
style.configure("TButton", font=("Helvetica", 12), padding=10, background="lightblue")
style.configure("TLabel", background="blue", foreground="white", font=("Helvetica", 12))

tk.Label(root, text="Input File:").grid(row=0, column=0, padx=10, pady=5, sticky='w')
tk.Entry(root, textvariable=input_file_path, width=50).grid(row=0, column=1, padx=10, pady=5, sticky='w')
ttk.Button(root, text="Browse", command=select_input_file).grid(row=0, column=2, padx=10, pady=5)

ttk.Button(root, text="Run Parser", command=run_parser).grid(row=1, columnspan=3, pady=20)

# Make the Text widget expand with window resizing
root.grid_rowconfigure(4, weight=1)
root.grid_columnconfigure(1, weight=1)

# Start the Tkinter event loop
root.mainloop()
