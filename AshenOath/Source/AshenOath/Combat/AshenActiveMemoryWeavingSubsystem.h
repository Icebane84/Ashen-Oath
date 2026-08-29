// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenActiveMemoryWeavingSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeavingDensityUpdatedSignature, int32, ThreadCount, float, Tension);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnThreadSnappedSignature, float, SanityBacklash);

/**
 * UAshenActiveMemoryWeavingSubsystem
 * GameInstance Subsystem managing active memory loom state, thread tension calculations,
 * and translating FSoulStateVector into physical filaments.
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

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Weaving|Events")
	FOnWeavingDensityUpdatedSignature OnWeavingDensityUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Weaving|Events")
	FOnThreadSnappedSignature OnThreadSnapped;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	void CalculateWeavingDensity(float IntegrationDebt, float TrustScalar, int32& OutThreadCount, float& OutTension);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	bool RegisterThreadSnapEvent(AActor* KaelenActor = nullptr);
};
