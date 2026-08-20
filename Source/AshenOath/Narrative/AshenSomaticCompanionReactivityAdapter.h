// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticCompanionReactivityAdapter.generated.h"

/**
 * UAshenSomaticCompanionReactivityAdapter
 * Companions comment on Kaelen's heavy breathing and physical exhaustion during intense exertion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticCompanionReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSomaticCompanionReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerFatigueCallout(FName CompanionID, float StaminaPercent);
};
