<div dir="rtl">

# نام پروژه

> یک جمله درباره‌ی پروژه (مثلاً: شبیه‌ساز Git و GitHub یا شبیه‌ساز Linux). این خط را ویرایش کنید.

## راهنمای شروع (بعد از ساختن Repository این بخش را پاک کنید)

۱. روی دکمه‌ی **Use this template** بزنید و Repository گروه را بسازید.
۲. هم‌گروهی‌تان را از Settings → Collaborators اضافه کنید.
۳. هر نفر Branch مخصوص خودش را بسازد: `student-1` و `student-2`.
۴. قالب پیام Commit را فعال کنید: `git config commit.template .gitmessage`
۵. فایل‌های `docs/clean-code.md` و `docs/commit-culture.md` را بخوانید.
۶. این README را کامل کنید (بخش‌های پایین).

## اعضای گروه

| نام | شماره دانشجویی | Branch |
| --- | --- | --- |
| نفر اول | | `student-1` |
| نفر دوم | | `student-2` |

## امکانات

- فهرست امکانات پیاده‌سازی‌شده را اینجا بنویسید.

## پیش‌نیازها

- کامپایلر با پشتیبانی C++17 (مثل GCC 9+ یا Clang 10+)
- CMake نسخه‌ی ۳.۱۶ یا بالاتر
- Qt (فقط برای فاز ۴ و رابط گرافیکی)

## نصب و اجرا

```bash
cmake -S . -B build
cmake --build build
./build/ap_cli          # اجرای برنامه (در ویندوز: build\Debug\ap_cli.exe)
ctest --test-dir build  # اجرای تست‌ها
```

## ساختار پروژه

```
├── core/    # منطق برنامه؛ بدون وابستگی به Qt و بدون چاپ مستقیم
├── cli/     # رابط خط فرمان (فازهای ۱ تا ۳)
├── ui/      # رابط گرافیکی Qt (فاز ۴)
├── tests/   # تست‌ها
└── docs/    # راهنمای کد تمیز و فرهنگ Commit
```

## قراردادهای تیم

- [راهنمای کد تمیز](docs/clean-code.md)
- [فرهنگ Commit](docs/commit-culture.md)

## وضعیت فازها

| فاز | وضعیت | Tag |
| --- | --- | --- |
| ۱ | ⬜ | `phase-1` |
| ۲ | ⬜ | `phase-2` |
| ۳ | ⬜ | `phase-3` |
| ۴ | ⬜ | `phase-4` |

</div>
