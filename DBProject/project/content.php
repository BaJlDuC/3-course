<p class="info">
    �� ������ ����� �� ������ ���������� ����(� �� ������) ���������� �� �����������. � ������� ������� ������� ��� ��
    �������� ����� ������ ������ ��� ������ ���������� �� ���������� ����������. � ���� �� ��������� ��������������,
    � ��� ���� ����������� �������� ��� ������������ ���������� ��� �������� �����. ���� ����� ��������� �������
    � ������������:
</p>

<?php
function what() {
   echo "-_-";
}
header("Content-type: text/html; charset=windows-1251");
  $serverName = 'LAPTOP-92CJBHPJ\SERVERFORPROJECT';
  $connectionInfo = array('Database' => 'DataBaseForProject');
  $connect = sqlsrv_connect($serverName, $connectionInfo);
  if (!$connect) {
      echo "Connection could not be established\n";
      die(print_r(sqlsrv_errors(), true));
  }

  $query = "SELECT student.name, student.surname, student.patronymic, university.name, norm.name, results.result, results.date_of_completion, 
	teacher.surname, teacher.name, teacher.patronymic, student.gender FROM results 
	LEFT JOIN student
	  ON results.id_student = student.id_student
	LEFT JOIN norm
	  ON results.id_norm = norm.id_norm 
	LEFT JOIN university
	  ON student.id_university = university.id_university
	LEFT JOIN teacher
	  ON results.id_teacher = teacher.id_teacher
	ORDER BY results.date_of_completion DESC";
  $resultSql = sqlsrv_query($connect, $query);
  $fields = sqlsrv_num_fields($resultSql) - 1; //-1 because have a gender

echo "<table border='1', style='position: relative; left: 3%;'>";
echo "<tbody>\n";
echo "<tr>\n";
echo "<th>�������</th>\n";
echo "<th>���</th>\n";
echo "<th>��������</th>\n";
echo "<th>��. ���������</th>\n";
echo "<th>��������</th>\n";
echo "<th>���������</th>\n";
echo "<th>������</th>\n";
echo "<th>���� �����</th>\n";
echo "<th>������� �������������</th>\n";
echo "<th>��� �������������</th>\n";
echo "<th>�������� �������������</th>\n";
echo "</tr>\n";
  while ($row = sqlsrv_fetch_array($resultSql)) {
      echo "<tr>\n";
      //------------------------------------------------------------------------thrash
      $gender = $row[10];
      $norm = $row[4];
      $result = $row[5];
      $oneMoreQuery = "SELECT * FROM concrete_norm WHERE gender = '$gender' AND name = '$norm'";
      $oneMoreResult = sqlsrv_query($connect, $oneMoreQuery);
      $oneMoreFieldNumber = sqlsrv_num_fields($oneMoreResult);

      $rating = 0;
      while ($oneMoreRow = sqlsrv_fetch_array($oneMoreResult)) {
          $normName = $oneMoreRow[2];
          if (substr($normName, 0, 3) == "���") {
              if ($oneMoreRow[5] == 5 && $result <= $oneMoreRow[4] && $rating == 0) {
                  $rating = 5;
              }
              else if ($oneMoreRow[5] == 4 && $result <= $oneMoreRow[4] && $rating == 0) {
                  $rating = 4;
              }
              else if ($oneMoreRow[5] == 3 && $result <= $oneMoreRow[4] && $rating == 0) {
                  $rating = 3;
              }
              else if ($rating == 0){
                  $rating = "�� ����";
              }
          }
          else {
              if ($oneMoreRow[5] == 5 && $result >= $oneMoreRow[4] && $rating == 0) {
                  $rating = 5;
              }
              else if ($oneMoreRow[5] == 4 && $result >= $oneMoreRow[4] && $rating == 0) {
                  $rating = 4;
              }
              else if ($oneMoreRow[5] == 3 && $result >= $oneMoreRow[4] && $rating == 0) {
                  $rating = 3;
              }
              else if ($rating == 0) {
                  $rating = "�� ����";
              }
          }
      }
      //------------------------------------------------------------------------------
      for ($i = 0; $i < $fields; $i++) {
          if ($i == 6)
          {
              echo "<th>".$rating."</th>";
              echo "<th>".$row[$i]->format('Y-m-d')."</th>";
          }
          else {
              echo "<th>".$row[$i]."</th>";
          }
      }
      echo "</tr>\n";
  }
echo "</tbody>\n";
echo "</table>\n";


  sqlsrv_close($connect);