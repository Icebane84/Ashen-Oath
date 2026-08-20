// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenLightDarkModeEcosystemEvaluatorComponent.generated.h"

/**
 * UAshenLightDarkModeEcosystemEvaluatorComponent
 * Evaluates creature behavioral responses to Kaelen's Light vs Dark mode (e.g. Glimmerdrake placid calm vs Sorrow-Leech attraction).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLightDarkModeEcosystemEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLightDarkModeEcosystemEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Ecosystem")
	EEcosystemModeReaction EvaluateCreatureReaction(FName CreatureID, bool bIsKaelenInDarkMode) const;
};
