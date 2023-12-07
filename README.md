## Beamdynamics Assignment - Amaan
In this README file I will provide you with everything you need to evaluate my assignment.
I will leave the database empty. Therefore you must create the equipments and manufacturers **YOURSELF** using the cURL I have provided below.

*In case of any discrepancies please feel free to mail me at : amaan5800@gmail.com*


## Testing the REST API
### Create all Manufacturers
```cURL
curl --location 'http://13.48.26.55:3000:3000/manufacturer' \
--header 'Content-Type: application/json' \
--data '[
    {"id":"123e4567-e89b-12d3-a456-426614174000","name": "Humans"},
    {"id":"123e4567-e89b-12d3-a456-426614174001","name": "Elves"},
    {"id":"123e4567-e89b-12d3-a456-426614174002","name": "Dwarves"}
]'
```
*You can also create a single manufacturer by passing only one record to the data array*

### Create all Equipments ( Relationship with manufacturer is automatically created)
```cURL
curl --location 'http://13.48.26.55:3000/equipment' \
--header 'Content-Type: application/json' \
--data '[
  {
    "id": "123e4567-e89b-12d3-a456-42661417400a",
    "model": "The Anduril Sword",
    "serialNumber": "000001A",
    "manufacturerId": "123e4567-e89b-12d3-a456-426614174000"
  },
  {
    "id": "123e4567-e89b-12d3-a456-42661417400b",
    "model": "Long Battle Bow",
    "serialNumber": "000001A",
    "manufacturerId": "123e4567-e89b-12d3-a456-426614174001"
  },
  {
    "id": "123e4567-e89b-12d3-a456-42661417400c",
    "model": "Golden Helm",
    "serialNumber": "000001B",
    "manufacturerId": "123e4567-e89b-12d3-a456-426614174000"
  },
  {
    "id": "123e4567-e89b-12d3-a456-42661417401c",
    "model": "Sacred Ring",
    "serialNumber": "000001B1",
    "manufacturerId": "123e4567-e89b-12d3-a456-426614174002"
  },
  {
    "id": "123e4567-e89b-12d3-a456-42661417400d",
    "model": "Shield of Gondor",
    "serialNumber": "000001A",
    "manufacturerId": "123e4567-e89b-12d3-a456-426614174000"
  },
  {
    "id": "123e4567-e89b-12d3-a456-42661417400e",
    "model": "Leather Breastplate",
    "serialNumber": "000001C",
    "manufacturerId": "123e4567-e89b-12d3-a456-426614174000"
  }
]'
```
*You can also create a single equipment by passing only one record to the data array*

### Delete a Manufacturer (Note : This will also delete all the equipments linked to the Manufacturer)
```cURL
curl --location --request DELETE 'http://13.48.26.55:3000:3000/manufacturer/123e4567-e89b-12d3-a456-426614174000'
```

### Delete an Equipment
```cURL
curl --location --request DELETE 'http://localhost:3000/equipment/123e4567-e89b-12d3-a456-42661417400e'
```

### Update a Manufacturer 
```cURL
curl --location --request PUT 'http://13.48.26.55:3000/manufacturer/123e4567-e89b-12d3-a456-426614174001' \
--header 'Content-Type: application/json' \
--data '{"name": "High Elves"}'
```

### Update an Equipment 
```cURL
curl --location --request PUT 'http://13.48.26.55:3000/equipment/123e4567-e89b-12d3-a456-42661417400e' \
--header 'Content-Type: application/json' \
--data '{"model": "Forbidden Nectar", "serialNumber": "093461Z"}'
```

### Update the Manufacturer of an Equipment (Update relationship)
```cURL
curl --location --request PUT 'http://13.48.26.55:3000:3000/equipment/manufacturer/e1f22531-2b49-4228-ab83-87315fc996b7' \
--header 'Content-Type: application/json' \
--data '{"manufacturerId": "1a225537-455d-491f-a120-5dbeb4aaf5d0"}'
```



You can also fork my Postman collection here to test all endpoints with more control :
https://www.postman.com/descent-module-cosmologist-24341852/workspace/beamdynamics-amaan/collection/20327661-b0fb0082-43b3-4848-b7a1-4739b507c74b?action=share&creator=20327661














1. Click **Source** on the left side.
2. Click the README.md link from the list of files.
3. Click the **Edit** button.
4. Delete the following text: *Delete this line to make a change to the README from Bitbucket.*
5. After making your change, click **Commit** and then **Commit** again in the dialog. The commit page will open and you’ll see the change you just made.
6. Go back to the **Source** page.

---

## Create a file

Next, you’ll add a new file to this repository.

1. Click the **New file** button at the top of the **Source** page.
2. Give the file a filename of **contributors.txt**.
3. Enter your name in the empty file space.
4. Click **Commit** and then **Commit** again in the dialog.
5. Go back to the **Source** page.

Before you move on, go ahead and explore the repository. You've already seen the **Source** page, but check out the **Commits**, **Branches**, and **Settings** pages.

---

## Clone a repository

Use these steps to clone from SourceTree, our client for using the repository command-line free. Cloning allows you to work on your files locally. If you don't yet have SourceTree, [download and install first](https://www.sourcetreeapp.com/). If you prefer to clone from the command line, see [Clone a repository](https://confluence.atlassian.com/x/4whODQ).

1. You’ll see the clone button under the **Source** heading. Click that button.
2. Now click **Check out in SourceTree**. You may need to create a SourceTree account or log in.
3. When you see the **Clone New** dialog in SourceTree, update the destination path and name if you’d like to and then click **Clone**.
4. Open the directory you just created to see your repository’s files.

Now that you're more familiar with your Bitbucket repository, go ahead and add a new file locally. You can [push your change back to Bitbucket with SourceTree](https://confluence.atlassian.com/x/iqyBMg), or you can [add, commit,](https://confluence.atlassian.com/x/8QhODQ) and [push from the command line](https://confluence.atlassian.com/x/NQ0zDQ).
