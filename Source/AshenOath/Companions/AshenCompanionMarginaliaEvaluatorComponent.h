// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionMarginaliaEvaluatorComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionMarginaliaEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionMarginaliaEvaluatorComponent();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void EvaluateMarginalia(const FSoulStateVector& StateVector);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Companions")
	FString GetActiveGarrettMarginalia() const { return ActiveGarrettMarginalia; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Companions")
	FString GetActiveSerafinaMarginalia() const { return ActiveSerafinaMarginalia; }

private:
	FString ActiveGarrettMarginalia;
	FString ActiveSerafinaMarginalia;
};
