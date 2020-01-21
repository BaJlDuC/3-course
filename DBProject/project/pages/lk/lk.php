<html>
<div style="width: auto; height: 60px; text-align: center; background-color: darkgrey;"><H1>�������� 1.0</H1></div>
<h2>������ �������</h2>
<title>������ �������</title>
<?php
header("Content-type: text/html; charset=windows-1251");

$fileWithName = fopen('../loginPage/name.txt', 'r');
$userName = fgets($fileWithName);
echo "����� ����������, $userName";
?>

<div style="width: 250px; margin-top: 5px">
    <button id="addBtn">�������� ����� ���������</button>
    </a></div>
<div style="position: relative; left: 30%; margin-top: -57px; width: 200px">
    <button id="updBtn">�������� ���������</button>
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
$norms = array('���', '������', '������������', '������ ��������');

?>
<div class="toMain" , style="margin-top: 20px"><a href="../../index.php">�� �������</a></div>
<div style="padding-top: 10px; padding-bottom: 10px"><a href="../lk/logout.php">�����</a></div>

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
                <p>�������� ��������</p>
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
                <p>�������� ��������</p>
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
                    <p>������� ���������</p>
                    <input class="input100" name="result" required placeholder="���������">
                    <span class="focus-input100"></span>
                </div>
                <div class="enterDate">
                    <p>������� ���� (����-��-��)</p>
                    <input class="input100" name="date" required placeholder="����">
                    <span class="focus-input100"></span>
                </div>
                <button style="margin-top: 20px" type="submit" name="addSubmit">��������</button>
            </form>
        </div><!-- content -->
    </div><!-- modal -->
    <!-- overlay ��� ����������� ���-->

    <div class="modal-upd">

        <a class="close-modal-upd">
            <svg viewBox="0 0 20 20">
                <path fill="#000000"
                      d="M15.898,4.045c-0.271-0.272-0.713-0.272-0.986,0l-4.71,4.711L5.493,4.045c-0.272-0.272-0.714-0.272-0.986,0s-0.272,0.714,0,0.986l4.709,4.711l-4.71,4.711c-0.272,0.271-0.272,0.713,0,0.986c0.136,0.136,0.314,0.203,0.492,0.203c0.179,0,0.357-0.067,0.493-0.203l4.711-4.711l4.71,4.711c0.137,0.136,0.314,0.203,0.494,0.203c0.178,0,0.355-0.067,0.492-0.203c0.273-0.273,0.273-0.715,0-0.986l-4.711-4.711l4.711-4.711C16.172,4.759,16.172,4.317,15.898,4.045z"></path>
            </svg>
        </a><!-- close modal -->

        <div class="modal-content-upd">
            <h3>������ ��������� c ������������: </h3>
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
            echo "<th>�������</th>\n";
            echo "<th>���</th>\n";
            echo "<th>��������</th>\n";
            echo "<th>��. ���������</th>\n";
            echo "<th>��������</th>\n";
            echo "<th>���������</th>\n";
            echo "<th>���� �����</th>\n";
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
                <p style="margin-right: 35px;">�������� ��������</p>
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
                <p style="margin-right: 30px;">�������� ��������</p>
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
                    <p style="width: 665px">������� �������</p>
                    <input class="input100" name="updSurname" required placeholder="�������">
                    <span class="focus-input100"></span>
                </div>
                <div class="enterName">
                    <p style="width: 625px">������� ���</p>
                    <input class="input100" name="updName" required placeholder="���">
                    <span class="focus-input100"></span>
                </div>
                <div class="enterPatronymic">
                    <p style="width: 660px">������� ��������</p>
                    <input class="input100" name="updPatronymic" required placeholder="��������">
                    <span class="focus-input100"></span>
                </div>-->
                <!--<div class="enterNorm">
                    <p style="margin-left: 262px; width: 502px">������� �������� (���, ������, ������������, ������
                        ��������)</p>
                    <input class="input100" name="updNorm" required placeholder="��������">
                    <span class="focus-input100"></span>
                </div>-->
                <div class="enterResult">
                    <p style="width: 765px">������� ����������� ���������</p>
                    <input class="input100" name="updResult" required placeholder="���������">
                    <span class="focus-input100"></span>
                </div>
                <div class="enterDate">
                    <p style="width: 835px">������� ����������� ���� (����-��-��)</p>
                    <input class="input100" name="updDate" required placeholder="����">
                    <span class="focus-input100"></span>
                </div>
                <button style="margin-top: 20px" type="submit" name="updSubmit">��������</button>
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
        echo "��������� ������ ���� ������";
    } else if (!strtotime($date)) {
        echo "������������ ���� ($date)";
    } else if ($date > date('Y-m-d')) {
        echo "���� �� ����� ���� ������ �������";
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
                echo "� ������� �������� ��� ���� ��������� �� ������ �������� </br>������� ������ '��������', ���� ������ �������� ���������";
                $haveResult = true;
            }
        }

        if (!$haveResult) {
            $query = "INSERT INTO results (id_student, id_norm, result, date_of_completion, id_teacher)
	        VALUES ($studentId, $normId, $result, '$date', $teacherId)";
            $resultSql = sqlsrv_query($connect, $query);
            echo "��������� ������� ��������";
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
        echo "������� �� ������ ���������� ���������";
    } else if (!is_numeric($result)) {
        echo "��������� ������ ���� ������";
    } else if ($checkRun == "���" && $result > $oldResult) {
        echo "����������� ��������� ������ ���� ����� �����������";
    } else if ($checkRun != "���" && $result < $oldResult) {
        echo "����������� ��������� ������ ���� ����� �����������";
    } else if (!strtotime($date)) {
        echo "������������ ���� ($date)";
    } else if ($date > date('Y-m-d') || ($date < $row[6]->format('Y-m-d'))) {
        echo "���� ����� �� ����� ���� ������ ������� � ������ ���� � ������� �����";
    } else {
        echo "�������";
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

        echo "��������� ��������";
    }
}
?>

</body>
</html>
