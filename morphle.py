from flask import Flask  
import os  
from datetime import datetime  
import subprocess  
import pytz  
import platform 

app = Flask(__name__)  

@app.route('/htop')  
def htop():  
    name = "M karthikeya"   
    username = os.getenv('USER', 'Unknown')  # Use getenv instead of getlogin

    ist = pytz.timezone('Asia/Kolkata')  
    server_time = datetime.now(ist).strftime('%Y-%m-%d %H:%M:%S.%f')  

    # command for macOS  
    if platform.system() == "Darwin":  # macOS
        top_output = subprocess.getoutput("top -l 1 -s 0 | head -10")
    else:  # Assume Linux
        top_output = subprocess.getoutput("top -bn1 | head -10")


    html_content = f"""  
    <h1>Server Details</h1>  
    <p><strong>Name:</strong> {name}</p>  
    <p><strong>Username:</strong> {username}</p>  
    <p><strong>Server Time (IST):</strong> {server_time}</p>  
    <pre>{top_output}</pre>  
    """  
    return html_content  

if __name__ == '__main__':  
    app.run(host='0.0.0.0', port=5000)