// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNullZonePostProcessAdapter.generated.h"

/**
 * UAshenNullZonePostProcessAdapter
 * Manages chromatic edge aberration, localized desaturation, and ash particle seeding for Null Zones.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNullZonePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNullZonePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void UpdateNullZonePostProcess(float ProximityRatio);
};
