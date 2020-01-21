<!DOCTYPE html>
<html lang="rus">
<head>
    <p>
        <a href="../../index.php">На главную</a>
    </p>
	<title>Войти</title>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
<!--===============================================================================================-->	
	<link rel="icon" type="image/png" href="images/icons/favicon.ico"/>
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="vendor/bootstrap/css/bootstrap.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="fonts/font-awesome-4.7.0/css/font-awesome.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="fonts/Linearicons-Free-v1.0.0/icon-font.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="vendor/animate/animate.css">
<!--===============================================================================================-->	
	<link rel="stylesheet" type="text/css" href="vendor/css-hamburgers/hamburgers.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="vendor/animsition/css/animsition.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="vendor/select2/select2.min.css">
<!--===============================================================================================-->	
	<link rel="stylesheet" type="text/css" href="vendor/daterangepicker/daterangepicker.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="css/util.css">
	<link rel="stylesheet" type="text/css" href="css/main.css">
<!--===============================================================================================-->
</head>
<body>
	
	<div class="limiter">
		<div class="container-login100">
			<div class="wrap-login100 p-t-50 p-b-90">
				<form action="loginPage.php" method="post" name="loginForm" class="login100-form validate-form flex-sb flex-w">
					<span class="login100-form-title p-b-51">
						Вход
					</span>

					
					<div class="wrap-input100 validate-input m-b-16" data-validate = "Введите логин">
						<input class="input100" type="text" name="username" placeholder="Логин">
						<span class="focus-input100"></span>
					</div>
					
					
					<div class="wrap-input100 validate-input m-b-16" data-validate = "Введите пароль">
						<input class="input100" type="password" name="password" placeholder="Пароль">
						<span class="focus-input100"></span>
					</div>
					
					<div class="flex-sb-m w-full p-t-3 p-b-24">
						<div>
							<p href="#" class="txt1">
								Забыли пароль? Обратитесь к администратору
							</p>
						</div>
					</div>

					<div class="container-login100-form-btn m-t-17">
						<button name="submit" type="submit" class="login100-form-btn">
							Войти
						</button>
					</div>

                    <?php
                    if (!empty($_REQUEST['password']) and !empty($_REQUEST['username']) ) {
                        header("Content-type: text/html; charset=utf-8");

                        $name = $_POST['username'];
                        $password = $_POST['password'];
                        $submit = $_POST['submit'];
                        $serverName = 'LAPTOP-92CJBHPJ\SERVERFORPROJECT';
                        $connectionInfo = array('Database' => 'DataBaseForProject');
                        $connect = sqlsrv_connect($serverName, $connectionInfo);

                        $query = "SELECT * FROM teacher WHERE teacher.login='$name'";
                        $resultSql = sqlsrv_query($connect, $query);
                        $fields = sqlsrv_num_fields($resultSql);
                        $row = sqlsrv_fetch_array($resultSql);
                        if (isset($submit)) {
                            if ($row[5] != $name || $row[6] != $password) {
                                echo "Неверный логин или пароль<br />";
                            } else {
                                echo "Идем в страницу лк...<br />";
                                session_start();
                                $_SESSION["user"] = $name;
                                $fileWithName = fopen('name.txt', 'w');
                                $fullName = $row[2].' '.$row[1].' '.$row[3];
                                fwrite($fileWithName, $fullName);
                                fclose($fileWithName);
                                //include 'lk.php';
                                header("Location: ../lk/lk.php");
                            }
                        }
                    }
                    ?>

				</form>
			</div>
		</div>
	</div>


	<div id="dropDownSelect1"></div>
	
<!--===============================================================================================-->
	<script src="vendor/jquery/jquery-3.2.1.min.js"></script>
<!--===============================================================================================-->
	<script src="vendor/animsition/js/animsition.min.js"></script>
<!--===============================================================================================-->
	<script src="vendor/bootstrap/js/popper.js"></script>
	<script src="vendor/bootstrap/js/bootstrap.min.js"></script>
<!--===============================================================================================-->
	<script src="vendor/select2/select2.min.js"></script>
<!--===============================================================================================-->
	<script src="vendor/daterangepicker/moment.min.js"></script>
	<script src="vendor/daterangepicker/daterangepicker.js"></script>
<!--===============================================================================================-->
	<script src="vendor/countdowntime/countdowntime.js"></script>
<!--===============================================================================================-->
	<script src="js/main.js"></script>

</body>
</html>
