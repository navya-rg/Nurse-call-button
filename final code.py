import nexmo
import smtplib
import serial

port="COM5" #Communication Port to which Arduino is connected
baud=9400
ard=serial.Serial(port,baud)

sender="navyarg11@gmail.com"
password="dholakpur123"
reciever="navyarg5@gmail.com"
SMTP_PORT=587

client = nexmo.Client(key='7fe56a9e', secret='qi1ItOKPRFKnU8rf')

messages={
	'1': "Emergency in patient's room",
	'2': "Patient is hungry",
	'3': "Patient is thirsty",
	'4': "Patient requires medicines",
	'5': "Patient is in pain",
	'6': "Patient needs to use the restroom",
	'7': "Patient needs change of clothes",
	'8': "Patient needs to see the doctor",
	'9': "Patient's room requires cleaing",
	'0': "Patient needs to meet family members"
}

while True:
	data=ard.readline().strip().decode('utf-8')
	print(data)
	msg=messages.get(data, "Invalid Input")
	print(msg)
	client.send_message({
    	'from': 'Nexmo',
    	'to': '919080320171',
    	'text': msg,
	});
	email=smtplib.SMTP('smtp.gmail.com', SMTP_PORT)
	email.starttls()
	email.login(sender,password)
	email.sendmail(sender, reciever, msg)


