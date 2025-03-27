#include "MyTestCPPLib.h"

FString UMyTestCPPLib::GenerateRandomNumber()
{
    TArray<int32> Digits = { 1,2,3,4,5,6,7,8,9 };
    FString Result;

    FRandomStream RandStream(FDateTime::Now().GetTicks()); // 시드 고정

    for (int32 i = 0; i < 3; ++i)
    {
        int32 Index = RandStream.RandRange(0, Digits.Num() - 1);
        Result += FString::FromInt(Digits[Index]);
        Digits.RemoveAt(Index); // 중복 방지
    }

    return Result;
}

FString UMyTestCPPLib::JudgeAnswer(const FString& PlayerInput, const FString& CorrectAnswer)
{
    if (PlayerInput.Len() != 3 || CorrectAnswer.Len() != 3) {
        return TEXT("Invalid input! Enter a 3-digit number.");
    }

    int Strikes = 0, Balls = 0;

    UE_LOG(LogTemp, Warning, TEXT("🔍 JudgeAnswer 호출됨: PlayerInput = %s (Len = %d), CorrectAnswer = %s"),
        *PlayerInput, PlayerInput.Len(), *CorrectAnswer);

    for (int i = 0; i < 3; i++) {
        FString PlayerChar = PlayerInput.Mid(i, 1);
        FString AnswerChar = CorrectAnswer.Mid(i, 1);

        if (PlayerChar == AnswerChar) {
            Strikes++;
        }
        else if (CorrectAnswer.Contains(PlayerChar)) {
            Balls++;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("🔍 결과: %d Strikes, %d Balls"), Strikes, Balls);

    if (Strikes == 3) {
        return TEXT("🎉 Correct! You win! 🎉");
    }

    return FString::Printf(TEXT("%d Strikes, %d Balls"), Strikes, Balls);
}

bool UMyTestCPPLib::IsValidInput(const FString& Input)
{
    if (Input.Len() != 3) return false;

    TSet<TCHAR> Digits;
    for (TCHAR C : Input)
    {
        if (C < '1' || C > '9') return false;
        Digits.Add(C);
    }

    return Digits.Num() == 3;
}

bool UMyTestCPPLib::IsCorrect(const FString& PlayerInput, const FString& CorrectAnswer)
{
    return PlayerInput == CorrectAnswer;
}
