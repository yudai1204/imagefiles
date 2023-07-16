import subprocess
import os
import shutil
import numpy as np
import cv2
import re
import time

T = 31


class Color:
    RED = '\033[31m'
    GREEN = '\033[32m'
    END = '\033[0m'


def isfloat(s):
    try:
        float(s)
    except ValueError:
        return False
    else:
        return True


def isint(s):
    try:
        int(s)
    except ValueError:
        return False
    else:
        return True


def float_validate(result, correct, accuracy):
    return abs(result - correct) <= accuracy


def int_validate_error(result, correct, accuracy):
    return (1-accuracy) * correct <= result <= (1+accuracy) * correct


def image_validate(result, correct):
    if not os.path.isfile(result):
        print("not exist result file", result)
        return False
    if not os.path.isfile(correct):
        print("not exist correct file", correct)
        return False
    result_img = cv2.imread(result)
    correct_img = cv2.imread(correct)
    return np.array_equal(result_img, correct_img)


def image_validate_psnr(result, correct, threshold):
    if not os.path.isfile(result):
        print("not exist result file", result)
        return (False, float('inf'))
    if not os.path.isfile(correct):
        print("not exist correct file", correct)
        return (False, float('inf'))
    result_img = cv2.imread(result)
    correct_img = cv2.imread(correct)
    return (threshold <= cv2.PSNR(result_img, correct_img), cv2.PSNR(result_img, correct_img))


def file_num_validate(result, correct):
    if not os.path.isfile(result):
        print("not exist result file", result)
        return False
    if not os.path.isfile(correct):
        print("not exist correct file", correct)
        return False
    with open(result) as f:
        result_data = re.split("[\n ]", f.read().removesuffix("\n"))
    with open(correct) as f:
        correct_data = re.split("[\n ]", f.read().removesuffix("\n"))
    if len(result_data) != len(correct_data):
        return False
    for i in range(len(result_data)):
        if not isfloat(result_data[i]):
            print("does not float value in result")
            return False
        if not isfloat(correct_data[i]):
            print("does not float value in correct")
            return False
        if not float_validate(float(result_data[i]), float(correct_data[i]), 1e-8):
            return False
    return True


def q1_run(img, mean, median):
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer01.py", img],
        stdout=subprocess.PIPE
    )
    p.wait()
    print("Q1", img, time.time()-start, "[sec]")
    output = re.split("\n", p.communicate()[0].decode().removesuffix("\n"))
    if len(output) != 2:
        return False
    if not isfloat(output[0]):
        print("does not float value in mean")
        return False
    if not isfloat(output[1]):
        print("does not float value in median")
        return False
    print("Q1", img, "mean", float_validate(float(output[0]), mean, 1e-8))
    print("Q1", img, "median", float_validate(float(output[1]), median, 1e-8))
    return float_validate(float(output[0]), mean, 1e-8) and float_validate(float(output[1]), median, 1e-8)


def q1():
    case_count = 3
    correct = 0
    correct += q1_run("tm/img1.png", 106.76513586956521, 95.0)
    correct += q1_run("tm/img2.png", 106.36149456521738, 94.0)
    correct += q1_run("tm/img3.png", 106.1773097826087, 93.0)
    if (case_count == correct):
        print("Q1", Color.GREEN, "Accept", Color.END)
    else:
        print("Q1", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q2_run(img1, img2, ssd):
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer02.py", img1, img2],
        stdout=subprocess.PIPE
    )
    p.wait()
    print("Q2", img1, img2, time.time()-start, "[sec]")
    output = re.split("\n", p.communicate()[0].decode().removesuffix("\n"))
    if len(output) != 1:
        return False
    if not isfloat(output[0]):
        print("does not float value in ssd")
        return False
    print("Q2", img1, img2, float_validate(float(output[0]), ssd, 1e-8))
    return float_validate(float(output[0]), ssd, 1e-8)


def q2():
    case_count = 2
    correct = 0
    correct += q2_run("tm/img1.png", "tm/img2.png", 2249066.0)
    correct += q2_run("tm/img1.png", "tm/img3.png", 12536530.0)
    if (case_count == correct):
        print("Q2", Color.GREEN, "Accept", Color.END)
    else:
        print("Q2", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q3_run(img1, img2, mse, psnr):
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer03.py", img1, img2],
        stdout=subprocess.PIPE
    )
    p.wait()
    print("Q3", img1, img2, time.time()-start, "[sec]")
    output = re.split("\n", p.communicate()[0].decode().removesuffix("\n"))
    if len(output) != 2:
        return False
    if not isfloat(output[0]):
        print("does not float value in mse")
        return False
    if not isfloat(output[1]):
        print("does not float value in psnr")
        return False
    print("Q3", img1, img2, "mse",  float_validate(
        float(output[0]), mse, 1e-8))
    print("Q3", img1, img2, "psnr",  float_validate(
        float(output[1]), psnr, 1e-8))
    return float_validate(float(output[0]), mse, 1e-8) and float_validate(float(output[1]), psnr, 1e-8)


def q3():
    case_count = 2
    correct = 0
    correct += q3_run("tm/img1.png", "tm/img2.png",
                      61.11592391304349, 30.269259793235683)
    correct += q3_run("tm/img1.png", "tm/img3.png",
                      340.6665760869565, 22.807508352632627)
    if (case_count == correct):
        print("Q3", Color.GREEN, "Accept", Color.END)
    else:
        print("Q3", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q4_run(target, template, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer04.py", target, template, run_output],
    )
    p.wait()
    print("Q4", target, template,  time.time()-start, "[sec]")
    print("Q4", target, template, image_validate(run_output, output))
    return image_validate(run_output, output)


def q4():
    case_count = 2
    correct = 0
    correct += q4_run("tm/target.png", "tm/template1.png", "tm/output4_1.png")
    correct += q4_run("tm/target.png", "tm/template2.png", "tm/output4_2.png")
    if (case_count == correct):
        print("Q4", Color.GREEN, "Accept", Color.END)
    else:
        print("Q4", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q5_run(target, template, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer05.py", target, template, run_output],
    )
    p.wait()
    print("Q5", target, template,  time.time()-start, "[sec]")
    print("Q5", target, template, image_validate(run_output, output))
    return image_validate(run_output, output)


def q5():
    case_count = 2
    correct = 0
    correct += q5_run("tm/target.png", "tm/template1.png", "tm/output5_1.png")
    correct += q5_run("tm/target.png", "tm/template2.png", "tm/output5_2.png")
    if (case_count == correct):
        print("Q5", Color.GREEN, "Accept", Color.END)
    else:
        print("Q5", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q6_run(target, template, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer06.py", target, template, run_output],
    )
    p.wait()
    print("Q6", target, template,  time.time()-start, "[sec]")
    print("Q6", target, template, image_validate(run_output, output))
    return image_validate(run_output, output)


def q6():
    case_count = 2
    correct = 0
    correct += q6_run("tm/target.png", "tm/template1.png", "tm/output6_1.png")
    correct += q6_run("tm/target.png", "tm/template2.png", "tm/output6_2.png")
    if (case_count == correct):
        print("Q6", Color.GREEN, "Accept", Color.END)
    else:
        print("Q6", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q7_run(target, template, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer07.py", target, template, run_output],
    )
    p.wait()
    print("Q7", target, template,  time.time()-start, "[sec]")
    print("Q7", target, template, image_validate(run_output, output))
    return image_validate(run_output, output)


def q7():
    case_count = 2
    correct = 0
    correct += q7_run("tm/target.png", "tm/template1.png", "tm/output7_1.png")
    correct += q7_run("tm/target.png", "tm/template2.png", "tm/output7_2.png")
    if (case_count == correct):
        print("Q7", Color.GREEN, "Accept", Color.END)
    else:
        print("Q7", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q8_run(input, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer08.py", input, run_output],
    )
    p.wait()
    print("Q8", input, time.time()-start, "[sec]")
    print("Q8", input, image_validate_psnr(run_output, output, T))
    return image_validate_psnr(run_output, output, T)[0]


def q8():
    case_count = 2
    correct = 0
    correct += q8_run("tm/rekka1.png", "tm/orig1.png")
    correct += q8_run("tm/rekka2.png", "tm/orig2.png")
    if (case_count == correct):
        print("Q8", Color.GREEN, "Accept", Color.END)
    else:
        print("Q8", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q9_run(img_in, x_in, y_in, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer09.py", img_in, x_in, y_in, run_output],
    )
    p.wait()
    print("Q9", img_in, x_in, y_in, time.time()-start, "[sec]")
    print("Q9", img_in, x_in, y_in, file_num_validate(run_output, output))
    return file_num_validate(run_output, output)


def q9():
    case_count = 2
    correct = 0
    correct += q9_run("det/img_cat.png", "216", "75", "det/res09a.txt")
    correct += q9_run("det/img_cat.png", "85", "35", "det/res09b.txt")
    if (case_count == correct):
        print("Q9", Color.GREEN, "Accept", Color.END)
    else:
        print("Q9", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q10_run(img_in, x_in, y_in, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer10.py", img_in, x_in, y_in, run_output],
    )
    p.wait()
    print("Q10", img_in, x_in, y_in, time.time()-start, "[sec]")
    print("Q10", img_in, x_in, y_in, file_num_validate(run_output, output))
    return file_num_validate(run_output, output)


def q10():
    case_count = 2
    correct = 0
    correct += q10_run("det/img_cat.png", "216", "75", "det/res10a.txt")
    correct += q10_run("det/img_cat.png", "85", "35", "det/res10b.txt")
    if (case_count == correct):
        print("Q10", Color.GREEN, "Accept", Color.END)
    else:
        print("Q10", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q11_run(fname_in, fname_out):
    run_fname_out = "temp/" + fname_out
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer11.py", fname_in, run_fname_out],
    )
    p.wait()
    print("Q11", fname_in, time.time()-start, "[sec]")
    print("Q11", fname_in, image_validate(run_fname_out, fname_out))
    return image_validate(run_fname_out, fname_out)


def q11():
    case_count = 2
    correct = 0
    correct += q11_run("det/img_cat.png", "det/res11cat.png")
    correct += q11_run("det/img_thai.png", "det/res11thai.png")
    if (case_count == correct):
        print("Q11", Color.GREEN, "Accept", Color.END)
    else:
        print("Q11", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q12_run(img_in, img_out):
    run_img_out = "temp/" + img_out
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer12.py", img_in, run_img_out],
        stdout=subprocess.PIPE
    )
    p.wait()
    print("Q12", img_in, time.time()-start, "[sec]")
    print("Q12", img_in, image_validate(run_img_out, img_out))
    return image_validate(run_img_out, img_out)


def q12():
    case_count = 2
    correct = 0
    correct += q12_run("det/img_cat.png", "det/res12cat.png")
    correct += q12_run("det/img_thai.png", "det/res12thai.png")
    if (case_count == correct):
        print("Q12", Color.GREEN, "Accept", Color.END)
    else:
        print("Q12", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q13_run(img_in, img_out):
    run_img_out = "temp/" + img_out
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer13.py", img_in, run_img_out],
        stdout=subprocess.PIPE
    )
    p.wait()
    print("Q13", img_in, time.time()-start, "[sec]")
    print("Q13", img_in, image_validate(run_img_out, img_out))
    return image_validate(run_img_out, img_out)


def q13():
    case_count = 2
    correct = 0
    correct += q13_run("det/img_cat.png", "det/res13cat.png")
    correct += q13_run("det/img_thai.png", "det/res13thai.png")
    if (case_count == correct):
        print("Q13", Color.GREEN, "Accept", Color.END)
    else:
        print("Q13", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q14_run(img_in, img_out):
    run_img_out = "temp/" + img_out
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer14.py", img_in, run_img_out],
        stdout=subprocess.PIPE
    )
    p.wait()
    print("Q14", img_in, time.time()-start, "[sec]")
    print("Q14", img_in, image_validate(run_img_out, img_out))
    return image_validate(run_img_out, img_out)


def q14():
    case_count = 2
    correct = 0
    correct += q14_run("det/img_cat.png", "det/res14cat.png")
    correct += q14_run("det/img_thai.png", "det/res14thai.png")
    if (case_count == correct):
        print("Q14", Color.GREEN, "Accept", Color.END)
    else:
        print("Q14", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q16_run(input, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer16.py", input, run_output],
    )
    p.wait()
    print("Q16", input, time.time()-start, "[sec]")
    print("Q16", input, file_num_validate(run_output, output))
    return file_num_validate(run_output, output)


def q16():
    case_count = 3
    correct = 0
    correct += q16_run("seg/kang.png", "seg/res16kang.txt")
    correct += q16_run("seg/cat.png", "seg/res16cat.txt")
    correct += q16_run("seg/late.png", "seg/res16late.txt")
    if (case_count == correct):
        print("Q16", Color.GREEN, "Accept", Color.END)
    else:
        print("Q16", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q17_run(input, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer17.py", input, run_output],
    )
    p.wait()
    print("Q17", input, time.time()-start, "[sec]")
    print("Q17", input, image_validate(run_output, output))
    return image_validate(run_output, output)


def q17():
    case_count = 3
    correct = 0
    correct += q17_run("seg/kang.png", "seg/res17kang.png")
    correct += q17_run("seg/cat.png", "seg/res17cat.png")
    correct += q17_run("seg/late.png", "seg/res17late.png")
    if (case_count == correct):
        print("Q17", Color.GREEN, "Accept", Color.END)
    else:
        print("Q17", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q18_run(input, seed_x, seed_y, t, output):
    run_output = "temp/" + output
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer18.py", input, seed_x, seed_y, t, run_output],
    )
    p.wait()
    print("Q18", input, seed_x, seed_y, t, time.time()-start, "[sec]")
    print("Q18", input, seed_x, seed_y, t, image_validate(run_output, output))
    return image_validate(run_output, output)


def q18():
    case_count = 2
    correct = 0
    correct += q18_run("seg/late.png", "180", "180", "140", "seg/res18late.png")
    correct += q18_run("seg/cat.png", "200", "180",
                       "120", "seg/res18cat.png")
    if (case_count == correct):
        print("Q18", Color.GREEN, "Accept", Color.END)
    else:
        print("Q18", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


def q19_run(img, count):
    start = time.time()
    p = subprocess.Popen(
        ["python", "exer19.py", img],
        stdout=subprocess.PIPE
    )
    p.wait()
    print("Q19", img, time.time()-start, "[sec]")
    output = re.split("\n", p.communicate()[0].decode().removesuffix("\n"))
    if len(output) != 1:
        return False
    if not isint(output[0]):
        print("does not int value")
        return False
    print("Q19", img, int_validate_error(int(output[0]), count, 0.03))
    return int_validate_error(int(output[0]), count, 0.03)


def q19():
    case_count = 2
    correct = 0
    correct += q19_run("seg/seeds1.jpg", 37)
    correct += q19_run("seg/seeds2.jpg", 122)
    if (case_count == correct):
        print("Q19", Color.GREEN, "Accept", Color.END)
    else:
        print("Q19", Color.RED, "Wrong", Color.END,
              "(failed", case_count - correct, "case)")


if __name__ == "__main__":
    os.makedirs("./temp", exist_ok=True)
    shutil.rmtree("./temp")
    os.makedirs("./temp")
    os.makedirs("./temp/tm")
    os.makedirs("./temp/det")
    os.makedirs("./temp/seg")
    q1()
    q2()
    q3()
    q4()
    q5()
    q6()
    q7()
    q8()
    q9()
    q10()
    q11()
    q12()
    q13()
    q14()
    q16()
    q17()
    q18()
    q19()
