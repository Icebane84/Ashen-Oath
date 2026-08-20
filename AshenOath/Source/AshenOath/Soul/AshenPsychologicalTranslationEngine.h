// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenPsychologicalTranslationEngine.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPsychologicalTranslationExecutedSignature, FString, MindStateLabel, FString, ResolveLabel, FString, GarrettBehaviorLabel);

/**
 * UAshenPsychologicalTranslationEngine
 *
 * Engine translating Layer I engine variables into Layer II psychological state language.
 */
UCLASS()
class ASHENOATH_API UAshenPsychologicalTranslationEngine : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PsychologicalTranslation")
	void TranslateEngineVariables(float IntegrationDebt, float Resolve, float GarrettTrust);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PsychologicalTranslation|Events")
	FOnPsychologicalTranslationExecutedSignature OnTranslationExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PsychologicalTranslation")
	FString CurrentMindStateText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PsychologicalTranslation")
	FString CurrentResolveText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PsychologicalTranslation")
	FString CurrentGarrettBehaviorText;
};
