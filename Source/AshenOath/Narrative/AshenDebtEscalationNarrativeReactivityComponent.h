// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenDebtEscalationNarrativeReactivityComponent.generated.h"

/**
 * UAshenDebtEscalationNarrativeReactivityComponent
 * Narrative component modifying dialogue choices, unlocking panicked barks, and altering tone tables under high debt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDebtEscalationNarrativeReactivityComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDebtEscalationNarrativeReactivityComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Narrative")
	bool bPanickedDialogueOptionsUnlocked = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void UpdateNarrativeReactivity(EAshenIntegrationDebtStage Stage);
};
