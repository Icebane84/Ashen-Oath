// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenDynamicArenaBoundaryActor.generated.h"

/**
 * AAshenDynamicArenaBoundaryActor
 * 3D world physical barrier actor locking the arena perimeter during combat encounters.
 */
UCLASS()
class ASHENOATH_API AAshenDynamicArenaBoundaryActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenDynamicArenaBoundaryActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	bool bIsArenaLocked = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void SetArenaLockState(bool bLock);
};
