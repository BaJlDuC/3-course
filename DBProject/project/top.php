<H1>�������� 1.0</H1>
<p class="login">
    <?php
     $fileWithName = fopen('pages/loginPage/name.txt', 'r');
     $userName = fgets($fileWithName);
     if (empty($userName)) { ?>
         ��������������? <a href="pages/loginPage/loginPage.php">�����</a>
         <?
     }
     else
     {
         echo "����� ����������, <br/> $userName | "; ?>
    <a href="pages/lk/lk.php">������ �������</a>
    <?
     }
    ?>
</p>