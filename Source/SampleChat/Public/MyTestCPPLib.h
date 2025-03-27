#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyTestCPPLib.generated.h"

UCLASS()
class UMyTestCPPLib : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // ✅ 숫자 생성 (호스트가 호출하여 랜덤한 3자리 숫자를 만듦)
    UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
    static FString GenerateRandomNumber();

    // ✅ 판정 함수
    UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
    static FString JudgeAnswer(const FString& PlayerInput, const FString& CorrectAnswer);

    UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
    static bool IsValidInput(const FString& Input);

    UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
    static bool IsCorrect(const FString& PlayerInput, const FString& CorrectAnswer);

};

