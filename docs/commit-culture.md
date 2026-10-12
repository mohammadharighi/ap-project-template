<div dir="rtl">

# فرهنگ Commit (Commit Culture)

**درس برنامه‌نویسی پیشرفته — نسخه ۱.۰**

تاریخچه‌ی Git داستان پروژه‌ی شماست. هر Commit یک جمله از این داستان است و باید برای هم‌تیمی، TA و استاد قابل‌خواندن باشد. در این درس **قرارداد Commit یک توصیه نیست، یک استاندارد الزامی است** و رعایتش بخشی از معیار «مشارکت در GitHub» در نمره‌دهی است.

---

## ۱. قالب استاندارد

```
type(scope): description
```

مثال:

```
feat(branch): implement branch creation
fix(parser): handle invalid commands
refactor(filesystem): simplify directory traversal
test(commit): add commit history tests
docs(readme): add installation guide
```

### اجزای قالب

| بخش | توضیح |
| --- | --- |
| `type` | نوع تغییر (از جدول پایین) |
| `scope` | بخش یا ماژولی که تغییر کرده، داخل پرانتز |
| `description` | توضیح کوتاه و مشخص تغییر |

### انواع مجاز (`type`)

| نوع | کاربرد |
| --- | --- |
| `feat` | افزودن قابلیت جدید |
| `fix` | رفع باگ |
| `refactor` | بازنویسی کد بدون تغییر رفتار |
| `test` | افزودن یا اصلاح تست |
| `docs` | تغییر مستندات (README و کامنت مستندسازی) |
| `style` | فقط قالب‌بندی (فاصله، فرمت)، بدون تغییر منطق |
| `chore` | کارهای جانبی (تنظیمات build، `.gitignore` و ...) |

### نمونه‌ی scope
بهتر است scope نام ماژول واقعی پروژه‌ی شما باشد، مثل `branch`, `commit`, `parser`, `filesystem`, `merge`, `shell`, `ui`. هر گروه فهرست scopeهایش را در `README.md` بنویسد تا ثابت بماند.

---

## ۲. قواعد نوشتن description

- **زبان انگلیسی** باشد.
- **فعل امری** بنویسید: `add`, `fix`, `implement` (نه `added` یا `adding`).
- با **حرف کوچک** شروع شود و **آخرش نقطه** نگذارید.
- کوتاه باشد، **حداکثر حدود ۵۰ کاراکتر** در خط اول.
- بگوید «چه چیزی» تغییر کرد، نه اینکه «چقدر کار کردید».
- در صورت نیاز، بعد از یک خط خالی، توضیح کامل‌تر (چرا و چطور) در بدنه‌ی Commit بنویسید.

```
fix(merge): prevent crash when branches have no common ancestor

The merge function assumed a shared ancestor always exists.
Return an explicit error instead of dereferencing a null pointer.
```

---

## ۳. نمونه‌های درست و غلط

| غیرقابل‌قبول | قابل‌قبول |
| --- | --- |
| `update` | `feat(commit): store author and timestamp` |
| `final` | `fix(parser): reject empty command names` |
| `test123` | `test(branch): cover duplicate branch names` |
| `changes` | `refactor(filesystem): extract path normalization` |
| `fix bug` | `fix(shell): handle missing argument in cd command` |
| `done phase 2` | `feat(merge): implement fast-forward merge` |
| `asdf` | `docs(readme): describe build and run steps` |

قاعده‌ی ساده: اگر نتوانید از روی پیام بفهمید **دقیقاً چه چیزی** عوض شده، آن پیام غیرقابل‌قبول است.

### نمونه‌هایی برای هر دو پروژه

**شبیه‌ساز Git و GitHub:**
```
feat(init): create repository metadata folder
feat(add): stage files for the next commit
feat(branch): list all branches
fix(checkout): restore working directory correctly
feat(remote): implement push to remote repository
```

**شبیه‌ساز Linux:**
```
feat(shell): parse command and arguments
feat(ls): list directory contents
fix(cd): handle non-existent directory
refactor(filesystem): split file and directory classes
test(rm): add recursive deletion tests
```

**رابط گرافیکی (فاز ۴):**
```
feat(ui): add main window layout
feat(ui): connect command input to core
style(ui): align toolbar buttons
```

---

## ۴. Commit اتمی: هر Commit فقط یک تغییر

- هر Commit یک تغییر منطقی و مشخص باشد. نه یک ماه کار در یک Commit، نه ده Commit برای یک خط.
- اگر هنگام نوشتن پیام مجبور شدید بنویسید «و ... و ...»، آن را به چند Commit بشکنید.
- **Commit شکسته** (پروژه‌ای که کامپایل نمی‌شود) را وارد `main` نکنید.
- Commit را **کوچک و مکرر** بزنید، نه یک‌جا در شب تحویل.
- فایل‌های کامپایل‌شده و موقت را Commit نکنید (از `.gitignore` استفاده کنید).
- چند تغییر غیرمرتبط را با هم Commit نکنید.

---

## ۵. Branch و جریان کار گروه

ساختار Repository هر گروه:

| Branch | کاربرد |
| --- | --- |
| `main` | نسخه‌ی پایدار و قابل‌اجرای پروژه |
| `student-1` | کار نفر اول |
| `student-2` | کار نفر دوم |

هر فاز با یک **Tag** ثبت می‌شود: `phase-1`، `phase-2`، `phase-3`، `phase-4`.

### جریان کار روزمره

۱. روی Branch شخصی خودتان کار کنید.
۲. کار را به Commitهای کوچک و استاندارد تقسیم کنید.
۳. تغییرات را با **Pull Request** وارد `main` کنید.
۴. بهتر است هم‌تیمی‌تان PR را ببیند و بررسی کند.
۵. در پایان **هر فاز**، کدها ادغام و تست شوند و Tag فاز زده شود.
۶. در پایان فاز ۴، پروژه روی `main` باید کاملاً قابل‌اجرا باشد. ادغام را به آخر ترم نیندازید.

### دستورهای پایه

```bash
# رفتن به Branch شخصی
git switch student-1

# مشاهده‌ی تغییرات و افزودن
git status
git add path/to/file.cpp

# ثبت Commit با قالب استاندارد
git commit -m "feat(branch): implement branch creation"

# ارسال به GitHub
git push origin student-1

# دریافت آخرین تغییرات main
git pull origin main

# ثبت پایان فاز
git tag phase-1
git push origin phase-1
```

### قواعد ایمنی
- روی `main` مستقیم Commit نزنید؛ از طریق PR وارد کنید.
- روی Branch مشترک `git push --force` نزنید.
- قبل از شروع کار روزانه، آخرین تغییرات `main` را بگیرید تا تداخل کمتر شود.
- تداخل (conflict) را با هم‌تیمی‌تان حل کنید، نه با حذف کار او.

---

## ۶. Pull Request

عنوان PR از همان قالب Commit پیروی می‌کند. توضیح PR را با این قالب بنویسید:

```markdown
## چه کاری انجام شد؟
توضیح کوتاه تغییرات

## چطور تست شد؟
دستورها یا سناریوهایی که امتحان کردید

## نکات
مواردی که بازبین باید بداند
```

PR کوچک و متمرکز بزنید. یک PR بزرگ که چند هفته کار را در بر دارد، بازبینی‌پذیر نیست.

---

## ۷. تنظیم قالب پیش‌فرض Commit (اختیاری، پیشنهادی)

یک فایل به نام `.gitmessage` بسازید:

```
# type(scope): description  (حداکثر ۵۰ کاراکتر، انگلیسی، فعل امری)
#
# type: feat | fix | refactor | test | docs | style | chore
#
# توضیح کامل‌تر (چرا و چطور) در صورت نیاز:
```

و آن را فعال کنید:

```bash
git config commit.template .gitmessage
```

حالا هر بار `git commit` (بدون `-m`) بزنید، این راهنما در ویرایشگر نمایش داده می‌شود.

---

## ۸. این قرارداد چطور بررسی می‌شود؟

- تاریخچه‌ی Commitهای هر دو عضو گروه بررسی می‌شود.
- **تعداد Commit به‌تنهایی ملاک نیست.** کیفیت پیام، اندازه و معناداری Commitها، کیفیت کد و دفاع شفاهی در کنار هم دیده می‌شود.
- مشارکت هر نفر باید روی Branch خودش و در PRها قابل‌ردیابی باشد.
- Commitهای مبهم مثل `update` و `final` و `test123` و `changes` قابل‌قبول نیستند.

---

## ۹. چک‌لیست قبل از هر Commit

- [ ] پروژه کامپایل می‌شود.
- [ ] این Commit فقط یک تغییر مشخص را شامل می‌شود.
- [ ] پیام طبق قالب `type(scope): description` است.
- [ ] فایل کامپایل‌شده یا موقت وارد نشده است.
- [ ] کد دیباگ و کد کامنت‌شده حذف شده است.
- [ ] پیام را که بخوانم، بدون دیدن کد می‌فهمم چه شده.

</div>
