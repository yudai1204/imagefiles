import os
import sys
import glob
import subprocess


# 使い方
# $ python kiso2a_checker.py directory
#
# directoryは、ソースコード(8_1.c, 8_2.cなど)　が置いてあるdirectory
# 出力 : 実行結果の成否などが書かれたファイルが出力される



EXE_FILE_NAME = "tmp.exe"
TMP_OUTPUT_FNAME = "tmpout.txt"



def compare_files (fname1, fname2):
    with open(fname1) as f1:
        str1 = f1.read().split()
    with open(fname2) as f2:
        str2 = f2.read().split()
    return str1 == str2




# 対象ファイル fnameがあるフォルダに移動後に呼ぶ必要あり
# fname   : c code (e.g., 8_1.c)
# returns : True_or_False AND Error_Code
def check_program(fname) :
    print("\n\n----------------------")
    print("----CHECK_PROGRAM----", fname)

    # clear exe file and complie code
    if(os.path.isfile(EXE_FILE_NAME)):
        os.remove(EXE_FILE_NAME)
    subprocess.call("gcc " + fname + " -o " + EXE_FILE_NAME, shell=True)
    if not os.path.exists(EXE_FILE_NAME) :
        print( fname, "--No file/Fail Complie")
        return False, "CompErr"

    # run exe file and evaluate the updates
    result = True
    result_code = ""
    test_files = glob.glob("test/" + fname[:-2] + "*in.txt")
    for test_in in test_files:
        test_out = test_in[:-6] + "out.txt"
        subprocess.call( EXE_FILE_NAME + " < " + test_in + " > " + TMP_OUTPUT_FNAME, shell=True)
        ret = compare_files(test_out, TMP_OUTPUT_FNAME)
        if ret :
            print(test_in  +  ": OK!")
            result_code += "OK_"
        else   :
            print(test_in  + ": NG!!!!!")
            result = False
            result_code += "NG_"

    return result, result_code


def get_fname_from_path(path):
    idx = path.rfind("\\")
    if idx == -1 :
        idx = path.rfind("/")
    return path[idx+1:]


if __name__ == '__main__':
    dir = sys.argv[1]

    log_data = []
    for path in glob.glob(dir + "/*.c"):
        fname = get_fname_from_path(path)

        curr = os.getcwd()
        os.chdir(dir)
        res, code = check_program(fname)
        os.chdir(curr)

        log_data.append(res)
        log_data.append(code)

    with open(dir + "/log.txt", "w") as f:
        for s in log_data:
            f.write(str(s) + " ")
