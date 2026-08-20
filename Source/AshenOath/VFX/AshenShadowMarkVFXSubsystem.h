// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenShadowMarkVFXSubsystem.generated.h"

/**
 * UAshenShadowMarkVFXSubsystem
 * GameInstance Subsystem managing global character particle budget (capped at 2048 concurrent particles) and distance culling (> 1500uu).
 */
UCLASS()
class ASHENOATH_API UAshenShadowMarkVFXSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | VFX")
	int32 MaxConcurrentParticles = 2048;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | VFX")
	float MaxFrustumDistanceUnits = 1500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | VFX")
	bool ShouldCullSeepageVFX(float DistanceToCamera) const;
};
