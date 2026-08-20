// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDamageTextPool.generated.h"

class AAshenDamageTextActor;

/**
 * UAshenDamageTextPool
 * Localized, zero-allocation object pool for spawning floating combat damage texts.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDamageTextPool : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDamageTextPool();

protected:
	virtual void BeginPlay() override;

public:
	/** Displays the floating combat text at a location with randomized offsets. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|DamageText")
	void DisplayDamage(float Amount, FVector Position);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pool Settings", meta = (AllowPrivateAccess = "true"))
	int32 PoolSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pool Settings", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AAshenDamageTextActor> DamageTextClass;

	UPROPERTY(VisibleAnywhere, Category = "Pool State")
	TArray<AAshenDamageTextActor*> TextPool;

	int32 CurrentIndex;
};
