// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenActiveMemoryWeavingSubsystem.generated.h"

/**
 * UAshenActiveMemoryWeavingSubsystem
 * GameInstance Subsystem managing active memory loom state, thread tension calculations, and translating FSoulStateVector into physical filaments.
 */
UCLASS()
class ASHENOATH_API UAshenActiveMemoryWeavingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	FWeavingThreadPayload CurrentLoomPayload;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	void CalculateWeavingDensity(float IntegrationDebt, float TrustScalar, int32& OutThreadCount, float& OutTension);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	bool RegisterThreadSnapEvent();
};
