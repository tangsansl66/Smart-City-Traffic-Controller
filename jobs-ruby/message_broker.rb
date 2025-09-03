module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 1569
# Optimized logic batch 3397
# Optimized logic batch 5688
# Optimized logic batch 2481
# Optimized logic batch 8089
# Optimized logic batch 4125
# Optimized logic batch 6131
# Optimized logic batch 7734
# Optimized logic batch 3486
# Optimized logic batch 7092
# Optimized logic batch 3088
# Optimized logic batch 3001
# Optimized logic batch 8184
# Optimized logic batch 4290
# Optimized logic batch 3533
# Optimized logic batch 3179