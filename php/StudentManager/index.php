<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>主页</title>
</head>

<body>
    <form action="tools/add_ui.php" method="get">
        <input type="submit" value="添加">
    </form>
    <form action="tools/search.php" method="post">
        <input type="text" name="id" placeholder="请输入id">
        <input type="text" name="name" placeholder="请输入姓名">
        <input type="text" name="sex" placeholder="请输入性别">
        <input type="text" name="class" placeholder="请输入班级">
        <input type="submit">
    </form>
    <table border=1>
        <tr>
            <th>id</th>
            <th>姓名</th>
            <th>性别</th>
            <th>班级</th>
        </tr>
        <?php
        $db_host = "localhost";
        $db_username = "root";
        $db_password = "root";
        $db_name = "tang";
        $table_name = "user";
        $conn = mysqli_connect($db_host, $db_username, $db_password);
        if (!$conn) {
            die("Error:" . mysqli_error($conn));
        }
        mysqli_select_db($conn, $db_name);
        if (!$conn) {
            die("Error to connect database:" . mysqli_connect_error());
        }
        $sql = "select * from " . $table_name;
        $result = mysqli_query($conn, $sql);
        if (!$result) {
            die("ERROR:" . mysqli_error($conn));
        }
        while ($item = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>";
            echo $item["id"];
            echo "</td>";
            echo "<td>";
            echo $item["name"];
            echo "</td>";
            echo "<td>";
            echo $item["sex"];
            echo "</td>";
            echo "<td>";
            echo $item["class"];
            echo "</td>";
            echo "<td>";
            echo "<button> <a href=\"tools/delete.php?id=" . $item["id"] . "\">删除</a></button>";
            echo "<button> <a href=\"tools/modify_ui.php?id=" . $item["id"] . "&&sex=" . $item["sex"] . "&&name=" . $item["name"] . "&&class=" . $item["class"] . "\">修改</a></button>";
            echo "</td>";
            echo "</tr>";
        }
        ?>
    </table>
</body>

</html>