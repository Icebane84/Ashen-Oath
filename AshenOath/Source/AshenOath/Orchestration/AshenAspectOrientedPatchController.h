// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenAspectOrientedPatchController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAOPPatchAppliedSignature, FName, PatchID, FName, TargetSubsystem, bool, bIsPatchActive);

/**
 * UAshenAspectOrientedPatchController
 *
 * AOP Controller applying aspect-oriented patches to narrative and combat runtime systems.
 */
UCLASS()
class ASHENOATH_API UAshenAspectOrientedPatchController : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AOPController")
	void ApplyAspectOrientedPatch(FName PatchID, FName TargetSubsystem);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AOPController|Events")
	FOnAOPPatchAppliedSignature OnPatchApplied;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AOPController")
	int32 TotalActivePatchesCount = 0;
};
