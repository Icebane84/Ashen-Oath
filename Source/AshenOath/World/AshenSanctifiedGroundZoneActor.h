// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenWhiteFlameTypes.h"
#include "AshenSanctifiedGroundZoneActor.generated.h"

/**
 * AAshenSanctifiedGroundZoneActor
 * 3D world actor rendering consecrated white-gold terrain with persistent party stamina buffs (+20%).
 */
UCLASS()
class ASHENOATH_API AAshenSanctifiedGroundZoneActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSanctifiedGroundZoneActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	FSanctifiedGroundZone ZoneData;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	void InitializeZone(FVector Center, float Radius);
};
