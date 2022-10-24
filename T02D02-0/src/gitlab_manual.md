# Руководство по GitLab

## 1. Cоздание личного репозитория с нужным .gitignore и простым README.MD

> Для начала нам нужно локально создать папку и перейти в нее. Затем мы инициализируем git и указываем путь на origin нашего будущего репозитория
```bash
mkdir myrepo && cd myrepo; \
git init; git remote add origin git@gitlab.com:Flaiers/21-school.git; \
touch .gitignore README.MD
```

## 2. Cоздание веток develop и master

> При помощи команды switch принудительно создаем ветки
```bash
git switch -c master; \
git switch -c develop
```

## 3. Установка ветки develop по умолчанию

> Сообщаем удаленному git что develop является главной
```bash
git push -u origin develop
```

## 4. Cоздание issue на создание текущего мануала

> При помощи стандартных инструментов GitLab создаем issue
![](/misc/images/issue.png)

## 5. Cоздание ветки по issue

> При помощи стандартных инструментов GitLab создаем ветку с названием issue-1
![](/misc/images/branch.png)

## 6. Cоздание merge request по ветке в develop

> При помощи стандартных инструментов GitLab создаем merge request из ветки issue в develop
![](/misc/images/merge-request.png)

## 7. Комментирование и принятие реквеста

> После создания merge request комментируем и производим commit
![](/misc/images/merge-request.png)

## 8. Формирование стабильной версии в master с простановкой тега

> Создание ветки stable.
![](/misc/images/stable.png)

> Создание тега относительно stable
![](/misc/images/tag.png)

## 9. Работа с wiki проекта

> При помощи стандартных инструментов GitLab создаем страницу в Wiki
![](/misc/images/wiki.png)
