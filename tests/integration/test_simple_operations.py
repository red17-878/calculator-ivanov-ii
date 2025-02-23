import subprocess


def test_addition():
    res = subprocess.run(["./build/app.exe"], input="1 + 2", text=True, capture_output=True)
    assert res.returncode == 0
    assert int(res.stdout) == 3
