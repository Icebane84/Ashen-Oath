// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNullZoneCompanionReactivityAdapter.generated.h"

/**
 * UAshenNullZoneCompanionReactivityAdapter
 * Modulates companion anxiety animations and pathing caution when entering heavy Null Zones.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNullZoneCompanionReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNullZoneCompanionReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void NotifyCompanionNullZoneEntry(FName CompanionID, float ProximityRatio);
};
