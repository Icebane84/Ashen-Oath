// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenProtectiveInterceptDecoyActor.generated.h"

/**
 * AAshenProtectiveInterceptDecoyActor
 * 3D world target dummy for testing L3+R3 protective trajectory throws and partner lunges.
 */
UCLASS()
class ASHENOATH_API AAshenProtectiveInterceptDecoyActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenProtectiveInterceptDecoyActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	bool bWasTargetShoved = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void ReceiveProtectiveShove();
};
