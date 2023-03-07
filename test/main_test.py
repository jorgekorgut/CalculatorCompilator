import os
import subprocess
import re

INPUT_SRC = 'input'
TEST_SRC = 'test'

if not os.path.exists('bin'):
   print("== Construction de la calculatrice")
   subprocess.run(["make"])

print("== Debut test unitaires")

def list_files(search_path):
   result = []

    # Waking top-down from the root
   for root, dir, files in os.walk(search_path):
      result = files
   return result

files = list_files(TEST_SRC+'/'+INPUT_SRC)

i = 1
for file in files:
   testResult = ""

   testFile = open(TEST_SRC+'/'+INPUT_SRC+'/'+file)

   [expressionString, expectedResult] = testFile.read().splitlines()


   assert len(expressionString) != 0, "il n'y a pas d'expression dans le fichier " + file
   assert len(expectedResult) != 0, "il n'y a pas de resultat dans le fichier " + file

   proc = subprocess.Popen(["bin/calculer", expressionString], stdout = subprocess.PIPE)

   output = proc.stdout.read()

   evaluationExpression = re.findall("Result : (\\d+|Error)", str(output))[0]

   if evaluationExpression == expectedResult:
      testResult = "\033[32m OK \033[0m"
   else:
      testResult = "\033[31m FAIL \033[0m"

   print("[ "+testResult+" ] TEST "+str(i)+" : "+file)
   i+=1