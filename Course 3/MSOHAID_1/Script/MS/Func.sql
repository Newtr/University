DECLARE @v_TeamName NVARCHAR(255);

-- Call the function
SET @v_TeamName = dbo.GetTeamNameByProductId(2); -- Replace with the actual product ID

-- Print the result
PRINT 'Название команды: ' + ISNULL(@v_TeamName, 'NULL');
