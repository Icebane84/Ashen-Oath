// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSacredGroundSanctuaryZoneActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSacredGroundPulseSignature, FVector, ZoneCenter, float, HealAmountPerPulse);

/**
 * AAshenSacredGroundSanctuaryZoneActor
 *
 * Interactive World Actor placing holy sanctuary circles that continuously heal allies (PRS-001 Serafina Slice).
 */
UCLASS()
class ASHENOATH_API AAshenSacredGroundSanctuaryZoneActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSacredGroundSanctuaryZoneActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SacredGround")
	void TriggerSanctuaryPulse(float HealAmount = 25.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SacredGround|Events")
	FOnSacredGroundPulseSignature OnSanctuaryPulse;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredGround")
	bool bIsZoneActive = true;
};
