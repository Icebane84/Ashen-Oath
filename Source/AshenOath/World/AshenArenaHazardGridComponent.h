// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenArenaHazardGridComponent.generated.h"

/**
 * UAshenArenaHazardGridComponent
 * Manages spatial hazard zoning across the arena floor (void chasms, falling masonry, and desecrated sludge pools).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenArenaHazardGridComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenArenaHazardGridComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	TArray<FArenaHazardZoneData> ActiveHazards;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	bool SpawnHazardZone(FVector Location, float Radius, EArenaHazardType Type);
};
