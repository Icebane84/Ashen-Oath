// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenCombatStanceAIDirectorComponent.generated.h"

/**
 * UAshenCombatStanceAIDirectorComponent
 * AI Director modulating enemy defensive stances and proactive flank rotation to counter Kaelen's active stance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatStanceAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCombatStanceAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	FName EvaluateEnemyTacticalResponse(ECombatStance PlayerStance);
};
