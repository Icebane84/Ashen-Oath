// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenEmpathicReactionTriggerVolume.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEmpathicReactionTriggered, FName, CompanionID, FString, ZoneType);

/**
 * AAshenEmpathicReactionTriggerVolume
 * World volume firing companion emotional reactions when entering sacred or corrupted zones.
 */
UCLASS()
class ASHENOATH_API AAshenEmpathicReactionTriggerVolume : public AVolume
{
	GENERATED_BODY()
public:
	AAshenEmpathicReactionTriggerVolume();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | World")
	FOnEmpathicReactionTriggered OnEmpathicReactionTriggered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	FString ZoneReactionType = "SacredSanctuary";

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void TriggerZoneEmpathicReaction(FName CompanionID);
};
