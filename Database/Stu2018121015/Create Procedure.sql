--�����������
CREATE PROCEDURE preInfo
@StundentName VARCHAR(20)
AS
BEGIN
	SELECT Sno, Sname, Ssex, Sbirth
	FROM Student
	WHERE Student.Sname = @StundentName
END

--ִ�����
DECLARE @return int
--�з���ֵ
EXEC @return = preInfo 'Harry'
--��ʾ����ֵ
SELECT @return as ReturnValue