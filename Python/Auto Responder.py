#!/usr/bin/env python
# -*- coding: utf-8 -*-
	
import imaplib
import email
import smtplib
import time
import sys


addres ='email'
passwor= 'password'
mail = imaplib.IMAP4_SSL('imap.mail.ru')

mail.login(addres,passwor)
mail.select("inbox")

key = ["Dreamspark","@unicyb.kiev.ua"]
text ="some respond text"

			

def SendResponse(To):
	server = smtplib.SMTP('smtp.mail.ru', 587)

	server.ehlo()
	server.starttls()
	server.login(addres, passwor)

	server.sendmail(addres,To,text)

	


	
def loop():
	mail.select("inbox")
	n=0;
	(retcode, messages) = mail.search(None,'(UNSEEN)')
	if retcode== 'OK':
		for num in messages[0].split():
			
			typ,data = mail.fetch(num,'(RFC822)')
			for response_part in data:
				if isinstance(response_part, tuple):
					original = email.message_from_string(response_part[1])
					
					print (original['Return-path'])
					data = original['Subject']
					

					
					if(a for key in data):
						print(data)
						sender = email.utils.parseaddr(original['From'])
						SendResponse(sender[1])
					
					
while True:
	loop()
