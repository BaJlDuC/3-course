<html>
<div style="width: auto; height: 60px; text-align: center; background-color: darkgrey;"><H1>Физтабло 1.0</H1></div>
<h2>Личный кабинет</h2>
<title>Личный кабинет</title>
<?php
header("Content-type: text/html; charset=windows-1251");

$fileWithName = fopen('../loginPage/name.txt', 'r');
$userName = fgets($fileWithName);
echo "Добро пожаловать, $userName";
?>

<div style="width: 250px; margin-top: 5px">
    <button id="addBtn">Добавить новый результат</button>
    </a></div>
<div style="position: relative; left: 30%; margin-top: -57px; width: 200px">
    <button id="updBtn">Обновить результат</button>
</div>

<?php
$serverName = 'LAPTOP-92CJBHPJ\SERVERFORPROJECT';
$connectionInfo = array('Database' => 'DataBaseForProject');
$connect = sqlsrv_connect($serverName, $connectionInfo);
if (!$connect) {
    echo "Connection could not be established\n";
    die(print_r(sqlsrv_errors(), true));
}

$query = "SELECT student.name, student.surname, student.patronymic, student.birth_date, university.name FROM student
	LEFT JOIN university
	  ON student.id_university = university.id_university";
$resultSql = sqlsrv_query($connect, $query);
$oneMoreResultSql = sqlsrv_query($connect, $query);
$fields = sqlsrv_num_fields($resultSql);

$fullNames = array();
$norms = array('Бег', 'Прыжки', 'Подтягивание', 'Подъем туловища');

?>
<div class="toMain" , style="margin-top: 20px"><a href="../../index.php">На главную</a></div>
<div style="padding-top: 10px; padding-bottom: 10px"><a href="../lk/logout.php">Выйти</a></div>

<link href="https://fonts.googleapis.com/css?family=Roboto:300,400" rel="stylesheet">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/normalize/5.0.0/normalize.min.css">
<link rel="stylesheet" href="css/style.css">

<body>
<!-- modal add -->
<div class="modal-overlay">
    <div class="modal">

        <a class="close-modal">
            <svg viewBox="0 0 20 20">
                <path fill="#000000"
                      d="M15.898,4.045c-0.271-0.272-0.713-0.272-0.986,0l-4.71,4.711L5.493,4.045c-0.272-0.272-0.714-0.272-0.986,0s-0.272,0.714,0,0.986l4.709,4.711l-4.71,4.711c-0.272,0.271-0.272,0.713,0,0.986c0.136,0.136,0.314,0.203,0.492,0.203c0.179,0,0.357-0.067,0.493-0.203l4.711-4.711l4.71,4.711c0.137,0.136,0.314,0.203,0.494,0.203c0.178,0,0.355-0.067,0.492-0.203c0.273-0.273,0.273-0.715,0-0.986l-4.711-4.711l4.711-4.711C16.172,4.759,16.172,4.317,15.898,4.045z"></path>
            </svg>
        </a><!-- close modal -->

        <div class="modal-content">
            <form action="lk.php" method="post" name="addForm" class="addFormClass">
                <p>Выберите студента</p>
                <?php
                    echo "<select name='choiseStudent'>";
                $query = "SELECT student.name, student.surname, student.patronymic, student.birth_date, university.name FROM student
	LEFT JOIN university
	  ON student.id_university = university.id_university";
                $resultSql = sqlsrv_query($connect, $query);
                while ($row = sqlsrv_fetch_array($resultSql)) {
                    $fullName = "$row[0] $row[1] $row[2]";
                    echo "<option>$fullName</option>";
                }
                    echo "</select>";
                ?>
                <p>Выберите норматив</p>
                <?php
                    echo "<select name='norm'>";
                    $query = "SELECT * FROM norm";
                    $resultSql = sqlsrv_query($connect, $query);
                while ($row = sqlsrv_fetch_array($resultSql)) {
                    echo "<option>$row[1]</option>";
                }
                echo "</select>";
                ?>
                <div class="enterResult">
                    <p>Введите результат</p>
                    <input class="input100" name="result" required placeholder="Результат">
                    <span class="focus-input100"></span>
                </div>
                <div class="enterDate">
                    <p>Введите дату (ГГГГ-ММ-ДД)</p>
                    <input class="input100" name="date" required placeholder="Дата">
                    <span class="focus-input100"></span>
                </div>
                <button style="margin-top: 20px" type="submit" name="addSubmit">Добавить</button>
            </form>
        </div><!-- content -->
    </div><!-- modal -->
    <!-- overlay был закрывающий див-->

    <div class="modal-upd">

        <a class="close-modal-upd">
            <svg viewBox="0 0 20 20">
                <path fill="#000000"
                      d="M15.898,4.045c-0.271-0.272-0.713-0.272-0.986,0l-4.71,4.711L5.493,4.045c-0.272-0.272-0.714-0.272-0.986,0s-0.272,0.714,0,0.986l4.709,4.711l-4.71,4.711c-0.272,0.271-0.272,0.713,0,0.986c0.136,0.136,0.314,0.203,0.492,0.203c0.179,0,0.357-0.067,0.493-0.203l4.711-4.711l4.71,4.711c0.137,0.136,0.314,0.203,0.494,0.203c0.178,0,0.355-0.067,0.492-0.203c0.273-0.273,0.273-0.715,0-0.986l-4.711-4.711l4.711-4.711C16.172,4.759,16.172,4.317,15.898,4.045z"></path>
            </svg>
        </a><!-- close modal -->

        <div class="modal-content-upd">
            <h3>Список студентов c результатами: </h3>
            <?php
            $serverName = 'LAPTOP-92CJBHPJ\SERVERFORPROJECT';
            $connectionInfo = array('Database' => 'DataBaseForProject');
            $connect = sqlsrv_connect($serverName, $connectionInfo);
            if (!$connect) {
                echo "Connection could not be established\n";
                die(print_r(sqlsrv_errors(), true));
            }

            $query = "SELECT student.name, student.surname, student.patronymic, university.name, norm.name, results.result, results.date_of_completion FROM results
	LEFT JOIN student
	  ON results.id_student = student.id_student
	LEFT JOIN norm
	  ON results.id_norm = norm.id_norm
	LEFT JOIN university
	  ON student.id_university = university.id_university
	ORDER BY results.date_of_completion DESC";
            $resultSql = sqlsrv_query($connect, $query);
            $fields = sqlsrv_num_fields($resultSql);
            $fullNamesWithResult = array();

            echo "<table border='1', style='position: relative; left: 24%;'>";
            echo "<tbody>\n";
            echo "<tr>\n";
            echo "<th>Фамилия</th>\n";
            echo "<th>Имя</th>\n";
            echo "<th>Отчество</th>\n";
            echo "<th>Уч. заведение</th>\n";
            echo "<th>Норматив</th>\n";
            echo "<th>Результат</th>\n";
            echo "<th>Дата сдачи</th>\n";
            echo "</tr>\n";
            while ($row = sqlsrv_fetch_array($resultSql)) {
                echo "<tr>\n";
                $fullNameWithResult = "$row[0] $row[1] $row[2]";
                array_push($fullNamesWithResult, $fullNameWithResult);
                for ($i = 0; $i < $fields; $i++) {
                    if ($i == 6) {
                        echo "<th>" . $row[$i]->format('Y-m-d') . "</th>";
                    } else {
                        echo "<th>" . $row[$i] . "</th>";
                    }
                }
                echo "</tr>\n";
            }
            echo "</tbody>\n";
            echo "</table>\n";
            ?>
            <form action="lk.php" method="post" name="updForm" class="updFormClass">
                <p style="margin-right: 35px;">Выберите студента</p>
                <?php
                echo "<select name='choiseStudentUpd', style='margin-left: 120px'>";
                $query = "SELECT student.name, student.surname, student.patronymic, university.name, norm.name, results.result, results.date_of_completion FROM results
	LEFT JOIN student
	  ON results.id_student = student.id_student
	LEFT JOIN norm
	  ON results.id_norm = norm.id_norm
	LEFT JOIN university
	  ON student.id_university = university.id_university
	ORDER BY results.date_of_completion DESC";
                $resultSql = sqlsrv_query($connect, $query);
                while ($row = sqlsrv_fetch_array($resultSql)) {
                    $fullName = "$row[0] $row[1] $row[2]";
                    echo "<option>$fullName</option>";
                }
                echo "</select>";
                ?>
                <p style="margin-right: 30px;">Выберите норматив</p>
                <?php
                echo "<select name='updNorm', style='margin-left: 50px;'>";
                $query = "SELECT * FROM norm";
                $resultSql = sqlsrv_query($connect, $query);
                while ($row = sqlsrv_fetch_array($resultSql)) {
                    echo "<option>$row[1]</option>";
                }
                echo "</select>";
                ?>
                <!-- <div class="enterSurname">
                    <p style="width: 665px">Введите фамилию</p>
                    <input class="input100" name="updSurname" required placeholder="Фамилия">
                    <span class="focus-input100"></span>
                </div>
                <div class="enterName">
                    <p style="width: 625px">Введите имя</p>
                    <input class="input100" name="updName" required placeholder="Имя">
                    <span class="focus-input100"></span>
                </div>
                <div class="enterPatronymic">
                    <p style="width: 660px">Введите отчество</p>
                    <input class="input100" name="updPatronymic" required placeholder="Отчество">
                    <span class="focus-input100"></span>
                </div>-->
                <!--<div class="enterNorm">
                    <p style="margin-left: 262px; width: 502px">Введите норматив (Бег, Прыжки, Подтягивание, Подъем
                        туловища)</p>
                    <input class="input100" name="updNorm" required placeholder="Норматив">
                    <span class="focus-input100"></span>
                </div>-->
                <div class="enterResult">
                    <p style="width: 765px">Введите обновленный результат</p>
                    <input class="input100" name="updResult" required placeholder="Результат">
                    <span class="focus-input100"></span>
                </div>
                <div class="enterDate">
                    <p style="width: 835px">Введите обновленную дату (ГГГГ-ММ-ДД)</p>
                    <input class="input100" name="updDate" required placeholder="Дата">
                    <span class="focus-input100"></span>
                </div>
                <button style="margin-top: 20px" type="submit" name="updSubmit">Обновить</button>
            </form>
        </div><!-- content -->
    </div><!-- modal -->
</div><!-- overlay -->

<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.0.0/jquery.min.js'></script>
<script src="js/index.js"></script>
<script src="js/index.js"></script>

<?php
if (isset($_POST['addSubmit'])) {

    $fullName = $_REQUEST['choiseStudent'];
    $arrayWithName = explode(" ", $fullName);

    $name = $arrayWithName[1];
    $surname = $arrayWithName[0];
    $patronymic = $arrayWithName[2];

    $norm = $_REQUEST['norm'];

    $result = $_REQUEST['result'];
    $date = $_REQUEST['date'];

    if (!is_numeric($result)) {
        echo "Результат должен быть числом";
    } else if (!strtotime($date)) {
        echo "Некорректная дата ($date)";
    } else if ($date > date('Y-m-d')) {
        echo "Дата не может быть больше текущей";
    }
    else {
        $query = "SELECT * FROM student WHERE name='$surname' AND surname='$name' AND patronymic='$patronymic'";
        $resultSql = sqlsrv_query($connect, $query);
        $row = sqlsrv_fetch_array($resultSql);
        $studentId = $row[0];

        $query = "SELECT * FROM norm WHERE name='$norm'";
        $resultSql = sqlsrv_query($connect, $query);
        $row = sqlsrv_fetch_array($resultSql);
        $normId = $row[0];

        $nameArray = explode(" ", $userName);
        $query = "SELECT * FROM teacher WHERE name='$nameArray[1]' AND surname='$nameArray[0]' AND patronymic='$nameArray[2]'";
        $resultSql = sqlsrv_query($connect, $query);
        $row = sqlsrv_fetch_array($resultSql);
        $teacherId = $row[0];

        $query = "SELECT student.name, student.surname, student.patronymic, university.name, norm.name, results.result, results.date_of_completion FROM results
	LEFT JOIN student
	  ON results.id_student = student.id_student
	LEFT JOIN norm
	  ON results.id_norm = norm.id_norm
	LEFT JOIN university
	  ON student.id_university = university.id_university";
        $resultSql = sqlsrv_query($connect, $query);
        $fields = sqlsrv_num_fields($resultSql);

        $haveResult = false;
        while ($row = sqlsrv_fetch_array($resultSql)) {
            $fullNameFromDB = "$row[0] $row[1] $row[2]";
            if ($fullNameFromDB == $fullName && $row[4] == $norm) {
                echo "У данного студента уже есть результат на данный норматив </br>Нажмите кнопку 'Обновить', если хотите изменить результат";
                $haveResult = true;
            }
        }

        if (!$haveResult) {
            $query = "INSERT INTO results (id_student, id_norm, result, date_of_completion, id_teacher)
	        VALUES ($studentId, $normId, $result, '$date', $teacherId)";
            $resultSql = sqlsrv_query($connect, $query);
            echo "Результат успешно добавлен";
        }
    }


    $name = '';
    $surname = '';
    $patronymic = '';
    $norm = '';
    $result = '';
    $date = '';
} else if (isset($_POST['updSubmit'])) {
    $fullName = $_REQUEST['choiseStudentUpd'];
    $fullNameArray = explode(" ", $fullName);
    $name = $fullNameArray[1];
    $surname = $fullNameArray[0];
    $patronymic = $fullNameArray[2];
    $norm = $_REQUEST['updNorm'];

    $result = $_REQUEST['updResult'];
    $date = $_REQUEST['updDate'];

    $query = "SELECT student.name, student.surname, student.patronymic, university.name, norm.name, results.result, results.date_of_completion, 
	teacher.surname, teacher.name, teacher.patronymic FROM results 
	LEFT JOIN student
	  ON results.id_student = student.id_student
	LEFT JOIN norm
	  ON results.id_norm = norm.id_norm 
	LEFT JOIN university
	  ON student.id_university = university.id_university
	LEFT JOIN teacher
	  ON results.id_teacher = teacher.id_teacher
	WHERE student.name = '$surname' AND student.surname = '$name' AND student.patronymic = '$patronymic' AND norm.name = '$norm'
	ORDER BY results.date_of_completion DESC";
    $resultSql = sqlsrv_query($connect, $query);
    $row = sqlsrv_fetch_array($resultSql);
    $normToUpd = $row[4];
    $checkRun = substr($normToUpd, 0, 3);
    $oldResult = $row[5];

    if ($norm != $normToUpd) {
        echo "Студент не сдавал введенного норматива";
    } else if (!is_numeric($result)) {
        echo "Результат должен быть числом";
    } else if ($checkRun == "Бег" && $result > $oldResult) {
        echo "Обновленный результат должен быть лучше предыдущего";
    } else if ($checkRun != "Бег" && $result < $oldResult) {
        echo "Обновленный результат должен быть лучше предыдущего";
    } else if (!strtotime($date)) {
        echo "Некорректная дата ($date)";
    } else if ($date > date('Y-m-d') || ($date < $row[6]->format('Y-m-d'))) {
        echo "Дата сдачи не может быть больше текущей и меньше даты с прошлой сдачи";
    } else {
        echo "Успешно";
        $query = "SELECT * FROM student WHERE name='$surname' AND surname='$name' AND patronymic='$patronymic'";
        $resultSql = sqlsrv_query($connect, $query);
        $row = sqlsrv_fetch_array($resultSql);
        $studentId = $row[0];

        $nameArray = explode(" ", $userName);
        $query = "SELECT * FROM teacher WHERE name='$nameArray[1]' AND surname='$nameArray[0]' AND patronymic='$nameArray[2]'";
        $resultSql = sqlsrv_query($connect, $query);
        $row = sqlsrv_fetch_array($resultSql);
        $teacherId = $row[0];

        $query = "UPDATE results
	      SET result = $result, date_of_completion = '$date', id_teacher = $teacherId
	      WHERE id_student = $studentId";
        $resultSql = sqlsrv_query($connect, $query);

        echo "Результат обновлен";
    }
}
?>

</body>
</html>
