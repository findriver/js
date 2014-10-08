<HTML>
	<HEAD>
		<Title> Login/SignUp </Title>
	<BODY>
		name = "login" align="right" action="LogIn.php" method="POST" >
			<BR> Your Email&nbsp;:
			<INPUT type="text" name="email" size="20">&nbsp;&nbsp;&nbsp;
			Password&nbsp;:
			<INPUT type="PASSWORD" name="password" size="20"> &nbsp;
			<INPUT type="submit" name="submit" value="Log In"/>
			</BR>
			<a href="logout.php">Forget your password? </a>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		</FORM>
		
		<FORM name = "signup" align="center" action="SignIn.php" method="POST">		
			<hr>
			<h1 style="font-size: 24px">Sign Up</h1>
			<INPUT type="text" name="username" value="Username" size ="50">&nbsp;
			<Br>
			<INPUT type="text" name="youremail" value="Your Email" size ="50">
			<BR>
			<INPUT type="text" name="password_1" value="Password&nbsp;(8~10 characters)" size ="50"> 
			<BR>
			<INPUT type="text" name="password_2" value="Re-enter Password" size ="50">
			<BR>
			<INPUT type="submit" name="signup" value="Sign Up"/>
		</FORM>
			
		
	</BODY>
	</HEAD>
</HTML>

