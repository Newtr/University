USE [MSOHAID]
GO
/****** Object:  StoredProcedure [dbo].[INSERT_ДОГОВОР]    Script Date: 12/8/2023 11:26:31 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- Procedures for the ТРУДОВЫЕ ДОГОВОРЫ table:
ALTER PROCEDURE [dbo].[INSERT_ДОГОВОР] (
	@p_Идентификатор INT,
    @p_Дата_Начала DATE,
    @p_Дата_Окончания DATE,
    @p_Тип_Договора NVARCHAR(255)
) AS
BEGIN
    INSERT INTO ТРУДОВЫЕ_ДОГОВОРЫ (Идентификатор_договора, ДАТА_НАЧАЛА_ДЕЙСТВИЯ_ДОГОВОРА, ДАТА_ОКОНЧАНИЯ_ДЕЙСТВИЯ_ДОГОВОРА, ТИП_ДОГОВОРА)
    VALUES (@p_Идентификатор, @p_Дата_Начала, @p_Дата_Окончания, @p_Тип_Договора);
END;
