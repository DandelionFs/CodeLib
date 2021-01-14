# -*- coding: utf-8 -*-
# Python Selenium address : https://pypi.org/project/selenium/
from selenium import webdriver
import random
import time
url = str(input('请输入调查问卷url：'))
t = int(input('请输入提交问卷次数：'))
# 设置提交问卷次数
for times in range(t):
    driver = webdriver.Chrome()
    # 'https://www.wenjuan.com/s/6VVJZfT/'
    driver.get(url)
    # 定位所有的问卷问题
    questions = driver.find_elements_by_css_selector('.matrix')
    for answers in questions:
        # 定位所有问卷问题选项
        answer = answers.find_elements_by_css_selector('.icheckbox_div')
        # 定位需要填写文字的选项，并填入相关内容
        if not answer:
            blank_potion = answers.find_element_by_css_selector(
                '.blank.option')
            blank_potion.send_keys('没有')
            continue
        choose_ans = random.choice(answer)
        choose_ans.click()
    subumit_button = driver.find_element_by_css_selector('#next_button')
    subumit_button.click()
    print('已经成功提交了{}次问卷'.format(int(times) + int(1)))
    # 延迟问卷结果提交时间，以免间隔时间太短而无法提交
    time.sleep(1)
    driver.quit()
