from flask import Flask,render_template,request
import serial
arduinoData=serial.Serial('COM4',9600)   ## starts serial communication with bluetooth port
                                          ## check which port bluetooth is using

"""It's important to make sure the pair is successful, all HC-06 chips have a default password of "1234"
Once paired, you must go to your bluetooth settings in windows and there will be an advance menu where you 
can find the outgoing COM port number, this is the number you will use in pyserial to open a serial connection
to the HC-06  """

##arduinoData.write('right')

app = Flask(__name__)

@app.route('/',methods=['GET', 'POST'])
def index():
        print(request.method)
        if request.method == 'POST':
            if request.form.get('Left') == 'Left':
                arduinoData.write(1)      ## 1 left     ## Sending data to arduino
                print("Left")
            elif  request.form.get('Right') == 'Right':
                arduinoData.write(2)   ## 2 right
                print("Right")
            elif  request.form.get('Straight') == 'Straight':
                arduinoData.write(3)     ## 3 straight
                print("Straight")
            elif  request.form.get('Pulling') == 'Pulling':
                arduinoData.write(4)   ## 4 pulling
                print("Pulling")
            elif  request.form.get('Gripping') == 'Gripping':
                arduinoData.write(5)        ## 5 gripping
                print("Gripping")
            elif  request.form.get('Back') == 'Back':
                arduinoData.write(6)   ## 6 back
                print("Back")
            elif  request.form.get('Throwing') == 'Throwing':
                arduinoData.write(7)   ## 7 throwing
                print("Throwing")
        return render_template("index.html")


app.run(debug=True)
