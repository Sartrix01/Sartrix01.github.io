<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="connexion.css">
</head>
<body>
    <div class="b1">
        <div class="b11">
        <h1>ESTHETE</h1>
        </div>
    </div>
    <div class="b13">
    <?php 
        if(isset($_GET['login_err']))
            {
                $err = htmlspecialchars($_GET['login_err']);

                switch($err)
                {
                    case 'password':
                    ?>
                        <div class="alert alert-danger">
                            <strong>Erreur</strong> mot de passe incorrect
                        </div>
                    <?php
                    break;

                    case 'email':
                    ?>
                        <div class="alert alert-danger">
                            <strong>Erreur</strong> email incorrect
                        </div>
                    <?php
                    break;

                    case 'already':
                    ?>
                        <div class="alert alert-danger">
                            <strong>Erreur</strong> compte non existant
                        </div>
                       <?php
                    break;
                }
            }
        ?> 
        <div class="b12"></div>
        <form action="verfi.php" method="post">
            <h2>Me connecter</h2>
            <label for="identifiant" class="l1">Entrer votre identifiant</label>
            <div class="form-group">
                <input type="email" name="email" class="t1" placeholder="Email" required="required" autocomplete="off">
            </div>
            <div class="form-group">
                <input type="password" name="password" class="t2" placeholder="Mot de passe" required="required" autocomplete="off">
            </div>
            <button type="submit" class="v1">Connexion</button>
        </form>
    <a href="index.html">
        <div class="b14">
            <h5>Accueil</h5>
        </div>
    </a>
    </div>
</body>
</html>