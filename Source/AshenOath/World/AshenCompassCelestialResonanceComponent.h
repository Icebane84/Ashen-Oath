// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenCompassCelestialResonanceComponent.generated.h"

/**
 * UAshenCompassCelestialResonanceComponent
 * Calculates needle deflection angle (0 deg to 360 deg) and magnetic shimmer towards active Heartstone Sanctuary fires.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompassCelestialResonanceComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompassCelestialResonanceComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	float NeedleBearingDegrees = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	ECompassResonanceState ResonanceState = ECompassResonanceState::Dormant;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	void CalculateCompassBearing(FVector PlayerLocation, FVector TargetSanctuaryLocation, bool bInNullZone);
};
